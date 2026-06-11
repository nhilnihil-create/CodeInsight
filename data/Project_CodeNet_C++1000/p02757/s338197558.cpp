#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include<map>

using namespace std;

int main()
{
    int N, P;
    string S;
    vector<int> mod, dmod;

    cin >> N >> P;
    cin >> S;
    reverse(S.begin(), S.end());
    if(P != 2 && P != 5){
        mod.resize(S.size());
        dmod.resize(S.size());
        map<int, int> modCount;
        modCount[0] = 1;
        dmod[0] = 1;
        mod[0] = (S[0] - '0') % P;
        if (!modCount.count(mod[0]))
        {
            modCount[mod[0]] = 1;
        }
        else
        {
            modCount[mod[0]]++;
        }

        for (int d = 1; d < S.size(); d++){

            dmod[d] = (dmod[d-1] * 10) % P;
            mod[d] = ((S[d] - '0') * dmod[d] + mod[d-1]) % P;
            if(!modCount.count(mod[d])){
                modCount[mod[d]] = 1;
            }else{
                modCount[mod[d]]++;
            }
        }

        long long result = 0;
        for (auto itr = modCount.begin(); itr != modCount.end(); itr++){
            long long n = itr->second;
            result += n * (n - 1) / 2;
        }

        cout << result << endl;
    }else{
        long long result = 0;
        for (int i = 0; i < S.size(); i++){
            if((S[i] - '0')%P == 0){
                result += S.size() - i;
            }
        }
        cout << result << endl;
    }
}
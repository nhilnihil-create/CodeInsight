#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> S(pow(2, N));
    for (int i = 0; i < pow(2, N); i++){
        cin >> S.at(i);
    }
    sort(S.begin(), S.end());

    vector<int> bornSlimes;
    bornSlimes.reserve(pow(2, N));
    bornSlimes.emplace_back(S.back());
    S.pop_back();

    bool flag = true;
    vector<int> newSlimes;
    newSlimes.reserve(pow(2, N - 1));
    vector<int>::iterator itr;
    for (int i = 1; i < N + 1; i++){
        for (int j : bornSlimes){
            itr = lower_bound(S.begin(), S.end(), j);
            if (itr == S.begin()){
                flag = false;
                break;
            }
            itr--;
            newSlimes.emplace_back(*itr);
            S.erase(itr);
        }
        if (!flag) break;
        bornSlimes.insert(bornSlimes.end(), newSlimes.begin(), newSlimes.end());
        newSlimes.clear();
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
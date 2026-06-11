#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,i,j,k;
    string S;
    cin >> N >> S;
    set<int> m;
    vector<bool> p(1000,true);
    for(i = 0;i < N - 2;i++){
        if (p[S[i] - '0']){
            for (j = i + 1; j < N - 1; j++){
                if (p[(S[j] - '0') * 10 + (S[i] - '0')]){
                    for (k = j + 1; k < N; k++){
                        m.insert((S[i] - '0') * 100 + (S[j] - '0') * 10 + (S[k] - '0'));
                    }
                    p[(S[j] - '0') * 10 + (S[i] - '0')] = false;
                }
            }
            p[S[i] - '0'] = false;
        }
    }
    cout << m.size() << endl;
}
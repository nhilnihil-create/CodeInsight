#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int t = S.size() , N = S.size();
    for(int i = 1; i < N; i++){
        if(S[i - 1] == S[i]){
            t--;
            i+=2;
        }
    }
    cout << t << endl;
}
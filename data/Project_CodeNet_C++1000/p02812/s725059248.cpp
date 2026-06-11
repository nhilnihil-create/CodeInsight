#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i = 0; i < N-2; ++i){
        if(S[i] == 'A'){
            if(S[i+1]=='B'){
                if(S[i+2]=='C') ans++;
            }
        }
    }
    cout << ans << endl;
}
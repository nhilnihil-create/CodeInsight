#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    cin >> S;
    char st = S[0];
    vector<int> A(S.size()+1);
    for(int i=0;i<S.size();i++){
       if(S[i]=='<'){
           A[i+1] = A[i]+1;
       }
    }
    for(int i=S.size()-1;i>=0;i--){
        if(S[i]=='>'){
            A[i] = max(A[i+1]+1,A[i]);
        }
    }
    ll ans = 0;
    rep(i,A.size()) ans += A[i];
    cout << ans << endl;
    return 0;
}
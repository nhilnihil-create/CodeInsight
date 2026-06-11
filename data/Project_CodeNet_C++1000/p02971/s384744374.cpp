#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    int first=0,second=-1;
    rep(i,n){
        if(first<A[i]){
            second=first;
            first=A[i];
        }
        else{
            if(second<A[i])
                second=A[i];
        }
    }
    rep(i,n){
        if(A[i]==first) cout<<second<<endl;
        else cout<<first<<endl;
    }
    return 0;
}
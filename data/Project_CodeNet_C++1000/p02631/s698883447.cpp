#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n,x=0;
    cin>>n;
    vector<int> dat(n);
    rep(i,n){
        cin>>dat[i];
        x=x^dat[i];
    }
    rep(i,n){
        int ans=dat[i]^x;
        cout<<ans<<" ";
    }
    return 0;
}
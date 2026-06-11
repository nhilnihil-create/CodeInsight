#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    int n,k,d,c,ans;
    cin>>n>>k;
    vector<int> v(n,-1);
    ans=n;
    rep(i,k){
        cin>>d;
        rep(j,d){
            cin>>c;
            c--;
            if(v[c]==-1){
            v[c]=1;
            ans--;
            }
        }
    }
cout<<ans;
}

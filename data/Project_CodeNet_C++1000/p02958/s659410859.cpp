#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
int main(){
    int n;cin>>n;
    vector<int> v(n);
    rep(i,n)cin>>v[i];
    int ans=0;
    rep(i,n){
        if(v[i]==i+1)continue;
        else ans++;
        if(ans>2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
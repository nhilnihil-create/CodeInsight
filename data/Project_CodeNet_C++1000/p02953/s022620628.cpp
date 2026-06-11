#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
int main(){
    int n;cin>>n;
    vector<int> v(n);
    rep(i,n)cin>>v[i];
    bool flag=true;
    for(int i=n-1;i>0;i--){
        if(v[i]>=v[i-1])continue;
        else v[i-1]--;
        if(v[i]<v[i-1]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}

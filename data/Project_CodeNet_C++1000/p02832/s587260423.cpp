#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int cnt=1;
    int ans=0;
    int a;
    rep(i,n){
        cin>>a;
        if(a!=cnt){
            ans++;
        }else{
            cnt++;
        }
    }
    if(ans==n) cout<<-1<<endl;
    else cout<<ans<<endl;
}
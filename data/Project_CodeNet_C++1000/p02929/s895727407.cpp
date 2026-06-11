#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    string s;
    cin>>n>>s;
    if(s[0]=='W'){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    int cnt=1;
    for(int i=1;i<2*n;i++){
        int num;
        if(s[i]=='B')num=1;
        else num=0;
        num=(num+cnt)&1;
        if(num)cnt++;
        else{
            if(cnt==0){
                cout<<0<<endl;
                return 0;
            }
            ans=(ans*cnt)%MOD;
            cnt--;
        }
    }
    if(cnt!=0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans=(ans*i)%MOD;
    }
    cout<<ans<<endl;
}

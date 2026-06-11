#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    int cnt=0;
    bool flag=1;
    ll ans=1;
    for(int i=0;i<s.size();i++){
        if(cnt&1){
            if(s[i]=='W'){
                cnt++;
            }
            else{
                ans*=cnt;
                ans%=mod;
                cnt--;
            }
        }
        else{
            if(s[i]=='B'){
                cnt++;
            }
            else{
                ans*=cnt;
                ans%=mod;
                cnt--;
            }
        }
        if(cnt<0){
            flag=0;break;
        }
    }
    //cout<<cnt<<endl;
    if(!flag||cnt!=0){
        printf("0\n");
        return 0;
    }
    for(int i=2;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}

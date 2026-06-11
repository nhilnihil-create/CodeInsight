#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string num;
map<int,int> mp;
int main(){
    mp[0]=1;
    ll ans=0,cnt=0,p=1,x;
    cin>>x>>x>>num;
    if(x==2||x==5){
        for(int i=0;i<num.length();i++){
            if((num[i]-'0')%x==0) ans+=(ll)i+1;
        }
    }
    else{
    for(int i=num.length()-1;i>=0;i--){
        cnt=(cnt+(ll)(num[i]-'0')*p)%x;
        ans+=mp[cnt],mp[cnt]++;
        p=p*10%x;
    }
    }
    printf("%lld",ans);
}

#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll mod=10007;

ll i,j,k,l;
vector<ll> dp(200001),cnt(10000);

int main(){
    int n,p;cin>>n>>p;
    string s;
    cin>>s;
    cnt.resize(p);
    for(i=0;i<200001;i++){dp[i]=0;}
    for(i=0;i<p;i++){cnt[i]=0;}
    
    cnt[0]++;

    ll pow_ten=1,ans=0;
    if(!(p==2 || p==5)){
        for(i=s.size()-1;i>=0;i--)
        {
           
            dp[i]=(dp[i+1]+(s[i]-'0')*pow_ten)%p;
            pow_ten*=10;
            pow_ten%=p;
            cnt[dp[i]]++;
        }

        for(i=0;i<p;i++){
        ans+=cnt[i]*(cnt[i]-1)/2;
        }
    }else{
        for(i=0;i<s.size();i++)
        {
            if((int)(s[i]-'0')%p==0){
                ans+=(i+1);
            }
        }
    }   

    cout<<ans<<endl;
    return 0;
}
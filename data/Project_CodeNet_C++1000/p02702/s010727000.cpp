#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>

const ll sz=2019;
ll tot[sz+2];

int main()
{
    ll a,b,c,d,p,q;


    string str;
    cin>>str;
    ll ans=0;

    for(ll i=0;str[i];i++){
        ll temp[sz+2];
        memset(temp,0,sizeof temp);

        for(ll j=0;j<sz;j++){
            p=(j*10ll + (str[i] - '0'))%sz;
            temp[p]+=tot[j];
        }
        ++temp[str[i]-'0'];

        ans+=temp[0];

        for(ll j=0;j<sz;j++) tot[j]=temp[j];
    }

    cout<<ans<<'\n';
}

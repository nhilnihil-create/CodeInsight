#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll prime1=129;
const ll prime2=131;

const ll mod1=1e9+7;
const ll mod2=1e9+9;

const ll sz=5e3+100;
ll sum[2][sz];
ll pr[2][sz];

ll len;
string str;

void Hash()
{
    ll i,j,k;
    sum[0][0]=sum[1][0]=0;
    for(i=1;i<=len;i++){
        sum[0][i]=((sum[0][i-1]*prime1) + (str[i-1]-'a'))%mod1;
        sum[1][i]=((sum[1][i-1]*prime2) + (str[i-1]-'a'))%mod2;
    }

    pr[0][0]=pr[1][0]=1;
    for(i=1;i<sz;i++) {
        pr[0][i]=(pr[0][i-1]*prime1)%mod1;
        pr[1][i]=(pr[1][i-1]*prime2)%mod2;
    }
}

bool check(ll l,ll r,ll p)
{
    ll i,j,k,q,x,y,pp;
    x=(((sum[0][l+p-1]-sum[0][l-1]*pr[0][p])%mod1)+mod1)%mod1;
    y=(((sum[1][l+p-1]-sum[1][l-1]*pr[1][p])%mod2)+mod2)%mod2;

    pp=(((sum[0][r+p-1]-sum[0][r-1]*pr[0][p])%mod1)+mod1)%mod1;
    q=(((sum[1][r+p-1]-sum[1][r-1]*pr[1][p])%mod2)+mod2)%mod2;

    if(x==pp && y==q) return true;
    else return false;
}

int main()
{
    ll x,p,q,i,j,k,m,l,r;
    cin>>len>>str;

    Hash();
    ll mx=0;

    for(i=1;i<=len;i++){
        for(j=i+1;j<=len;j++){
            l=1,r=min((j-i),len-j+1);
            while(l<=r){
                ll mid=(l+r)/2ll;
                if(check(i,j,mid)) mx=max(mx, mid), l=mid+1;
                else r=mid-1;
            }
        }
    }

    cout<<mx<<'\n';
}

///  file:///E:/ATcodeR(D,E,F)/E%20-%20Who%20Says%20a%20Pun_.pdf

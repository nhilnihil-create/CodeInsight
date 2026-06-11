#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a;}
string biggerIsGreater(string s){

	int n,l=-1,i,j,k,r=-3;
	char ch;
	n=s.size();
	r=n-1;
       i=n-2;
       while(i>=0 && s[i]>=s[i+1])i--;
       if(i<0)return s;
        j=n-1;
        while(j>i &&  s[j]<=s[i])j--;
        ch=s[j];s[j]=s[i];s[i]=ch;
        i++;
        j=n-1;
        while(i<j){
        	ch=s[j];s[j]=s[i];
        	s[i]=ch;
        	i++;j--;

        }
        return s;


}
ll bigmod(ll x,ll n,ll m)
{
    ll r=1;
    while(n>0)
    {
        if(n % 2 ==1)
            r=(r * x)%m;
        x=(x*x)%m;
        n=n/2;
    }
    return r;
}



int main(){
ll n;
while(cin>>n){
	ll mod=1000000007;
	ll k=bigmod(10,n,mod);
	ll p=2*bigmod(9,n,mod);
	ll m=bigmod(8,n,mod);
	k=((k%mod)-(p%mod)+mod)%mod;
	k+=(m%mod);
	k%=mod;



cout<<k<<endl;

}


	return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define fr(i,n) for(ll i=0;i<n;i++)
using namespace std;
const ll A = 1000005;
ll k[A],j[A];ll n;
bool pairwise(){
for(ll i=2;i<A;i++)
    {int cnt = 0;

        for(ll ii=i;ii<A;ii+=i)
        {
            cnt += j[ii];
        }
        if(cnt>1)
        {
            return false;
        }
    }
    return true;}

bool setwise(){
    ll gcd=k[0];
for(ll i=1;i<n;i++){
        gcd=__gcd(k[i],gcd);
        {if(gcd==1)return true;}
}
return false;}


int main() {
    cin>>n;
    fr(i,n)cin>>k[i],j[k[i]]++;
   if(pairwise())cout<<"pairwise coprime";
    else if(setwise())cout<<"setwise coprime";
    else  cout<<"not coprime";

    }

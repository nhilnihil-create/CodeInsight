#include<bits/stdc++.h>
#define lg long long int
#define loop(i,s,e) for(lg i=s;i<=e;i++)
#define iloop(i,s,e) for(lg i=e;i>=s;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007


using namespace std;

lg min(lg a,lg b)
{return a<b?a:b;}
lg max(lg a,lg b)
{return a>b?a:b;}
lg lcm(lg a ,lg b)
{
    return (a*b)/__gcd(a,b);
}
lg n,m,k,ans;
int main()
{
    cin>>n;
    string kk="";
    while(n>0)
    {
        lg i = n%26;
        i--;
        if(i<0) i=25;
        string h = "a";
        h[0]+=i;
        kk = h+kk;
        if(n%26==0) n--;
        n/=26;
        if(n==0) break;
    }
    cout<<kk<<endl;
}

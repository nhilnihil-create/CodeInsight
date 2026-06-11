/*jai_ganeshdeva*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pu push  //  adds the value to the last of the queue 
#define lld long long int
#define ins insert /// used in set to insert the values 
#define adv advance  /// used to increment the iterator
#define mp make_pair
#define fi first
#define se second
#define all(c) c.begin(),c.end()
#define PI 3.1415926
#define INF (lld)1e18
#define vl  vector<long long int >
#define vpll vector< pair<lld ,lld> >
#define vvl vector<vector<lld> > 
#define pll pair <lld,lld>
#define modA(cccc,bbbb ,p) (((cccc+bbbb)%p+p)%p)
#define modS(cccc,bbbb ,p) (((cccc-bbbb)%p+p)%p)
#define modM(cccc,bbbb ,p) ((((cccc%p)*(bbbb%p))%p+p)%p)

long long int modp(lld a,lld p,lld n)
{
    lld d[100];
    lld i,j,k,l;
    if(n==0) return 1;
    for(i=0;n>=1;i++)
    {
        d[i]=n%2;
        n/=2;
    }
    l=i;
    long long int e=1;
    if(d[0]==1) e*=(a%p);
    for(i=1;i<l;i++)
    {
        a*=a;
        a=a%p;
        if(d[i]==1) 
        {
            e*=a;
            e=e%p;
        }
    }
    return e%p;
}
lld modInverse(lld n, lld p) 
{ 
    return modp(n, p, p-2); 
}

/*lld fac[100001]; 

void getfac(lld p)
{
    fac[0] = 1; 
    for (lld i=1 ; i<=100000; i++) 
        fac[i] = fac[i-1]*i%p; 
}    

long long int nCrmodp(lld n, lld r,lld p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
     
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
}*/


lld gcd(lld a,lld b)
{
    if(a>b) return gcd(b,a);
    if(b%a==0) return a;
    else return gcd(b%a,a);
}

lld p1=1e9 + 7,p2=998244353;
lld l,r,mid,ans;
lld n,i,j,k,g,m;
lld x,y,n1,n2,h,z,c;
lld aa=1;



void solve()
{
    cin>>n;
    x=1;
    for(i=0;i<n;i++)
    {
        cin>>l;
        if(l==x) x+=1;
    }


    if(x==1) cout<<-1;
    else cout<<n-x+1;

    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t=1;
    
    //cin>>t;
    //cout<<t;
   //  getfac(p2);
    //check the value by which modulo is to be taken
    lld ans=0;
    for(int i=0;i<t;i++)
    {
   //     cout<<"Case #"<<i+1<<": ";
                  solve();
        cout<<"\n";
    }
    return 0;
}

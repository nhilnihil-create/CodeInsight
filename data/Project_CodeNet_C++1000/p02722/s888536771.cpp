#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define maa 1000000007
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=200001 ;
int main()
{
   fast ;
   ll n ;
   cin>>n ;

   if(n==2)
   {
       cout<<"1" ;
       exit(0) ;
   }
   ll ans=2 ;
   for(ll i=2;i*i<=n;i++){
    if(n%i==0){
        ll x=n/i ;
        while(x%i==0)
        {
            x/=i ;
        }

        if(x%i==1)
        {
            ans++ ;


        }
        if(i*i!=n)
        {
            x=i ;
            while(x%(n/i)==0)
            {
                x/=(n/i) ;
            }
            if(x%(n/i)==1)
            {

                ans++ ;

            }
        }
    }
   }

   ll k=n-1 ;
   for(ll i=2;i*i<=k;i++)
   {
       if(k%i==0)
       {

           ans++ ;


           if(i*i!=k)
           {

            ans++ ;

           }
       }
   }

   cout<<ans ;




}


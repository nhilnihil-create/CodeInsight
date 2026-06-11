#include<bits/stdc++.h>
using namespace std ;
#define f(i,s,n) for(int i=s;i<n;i++)
const int MAXN = 1e7+6 ;
typedef long long ll ;
vector<bool> sieve ;
vector<ll> ans ;
vector<int> temp ;
int n ;
void sieveOfEras()
{
    f(i,2,n+1)
    {
        // temp.clear() ;
        // temp.resize(n+1) ;
        // vector<int> temp(n+1) ;

        if(!sieve[i]) //prime
        {
            ans[i] = 2 ; //1 and itself
            temp[i] = 1 ;
            for(int j=i*2;j<=n;j+=i)
            {
                sieve[j] = true ;
                if((j/i)%i==0)
                    temp[j] = temp[(j/i)]+1 ;
                else temp[j] = 1 ;
                ans[j] *= (ll)(temp[j]+1) ;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin>>n; 
    sieve.resize(n+1) ;
    ans.resize(n+1,1) ;
    temp.resize(n+1) ;
    sieveOfEras() ;
    ll ret = 0 ;
    f(i,1,n+1) ret+=(i*ans[i]) ;
    cout<<ret<<"\n" ;

}
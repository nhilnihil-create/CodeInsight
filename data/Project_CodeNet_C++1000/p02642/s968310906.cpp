#include<bits/stdc++.h>
using namespace std ;
const int MAXN = 1e6+5 ;
vector<int> v ;
// bool arr[MAXN] ;
vector<bool> arr(MAXN) ;
int countz[MAXN] ;
void sieve()
{
    for(auto x:v)
    {
        if(!arr[x])
        {
            for(int i=2*x;i<MAXN;i+=x)
            {
                arr[i] = true ;
            }
        }
    }
}
int main()
{
    int n;cin>>n;
    v.resize(n) ;
    for(int i=0;i<n;i++) 
    {
        cin>>v[i]  ;
        countz[v[i]]++ ;
    }
    sort(v.begin(),v.end()) ;
    v.erase( unique( v.begin(), v.end() ), v.end() );
    sieve() ;
    int ans = 0 ;
    for(int i=0;i<v.size();i++) 
    {
        if(!arr[v[i]] && countz[v[i]]==1) 
            ans++ ;
    }
    cout<<ans<<"\n" ;
}
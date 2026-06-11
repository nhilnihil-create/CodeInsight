#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long count1(vector<long long> &vec,long long x)
{
    long long n=0;
    for(int i=0;i<vec.size();i++)
    {
        n+=(vec[i]-1)/x ;
    }
    return n ;
}
int main()
{
   ios_base::sync_with_stdio(false) ;
   cin.tie(NULL) ;
    
   long long int n ;
   long long int k ;
   
   cin>>n>>k ;
   vector<long long> vec(n) ;
   long long max1=0 ;
   
    for(int i=0 ;i<n ;i++)
    {
           cin>>vec[i] ;
           max1=max(max1,vec[i]) ;
    }
    long long l=1 ;
    long long r=max1 ;
    long long ans ;
    while(l<=r)
    {
        long long mid=(l+r)/2 ;
        if(count1(vec,mid) <= k)
        {
            ans=mid ;
            r=mid - 1 ;
        }
        else
        {
            l=mid+1 ;
        }
    }
    cout<<ans<<endl ;
    return 0 ;
}

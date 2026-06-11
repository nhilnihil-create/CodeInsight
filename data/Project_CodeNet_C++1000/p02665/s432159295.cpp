#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7 , mod = 1e9 + 7 ;

long long n ; 
long long x[N] ; 
long long a[N] ;

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
//        freopen("in.in" , "r" , stdin) ; 
        cin>>n ; 
        long long a[n+1] ; 
        long long ans = 0 , mx = 1 ;      
        long long rem = 0 ;   
        for(int i = 0 ;i <=n;i++){
                long long t ; 
                cin>>a[i] ; 
                rem+=a[i] ; 
        }
        x[n] = a[n] ; 
        for(int i = n ; i ; i--)
                x[i-1] = a[i-1] +  x[i] ; 
        for(int i = 0 ; i <=n;i++){
                long long t = a[i] ; 
                if(t > mx){
                        return cout<<-1,0 ; 
                }
                long long all = min(mx  , rem); 
                mx-=a[i] ; 
                ans+=all ;
                mx*=2 ;   
                if(mx > 1e15)
                        mx = 1e15 ; 
                rem-=a[i] ; 
        }
        cout<< ans ; 
        return 0;
}

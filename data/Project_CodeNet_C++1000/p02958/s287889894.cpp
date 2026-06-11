#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll  long long
#define mod int(1e9+7)
#define endl '\n'
#define ENGZ ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0) , cout.tie(0) ;
#define pi (acos(-1))
#define S second
#define F first
ll fp(ll n , ll p )
{
    if(p==0)
        return 1;
    if(p==1)
        return n ;
    ll res = fp(n,p/2) ;
    res=((res)*(res)) ;
    if(p%2)
        res=(res*n) ;
    return res ;
}

int main()
{
    ENGZ;
    int n , arr[101] , brr[101];
    int a = -1, b = -1 , c = 0;
    cin>>n ;
    for(int i=0 ; i<n ; i++)
        cin>>arr[i],brr[i]=arr[i] ;

    sort(arr,arr+n);
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]!=brr[i] && a == -1)
        {
            c++ ;
            a = i ;
        }
        else if(arr[i]!=brr[i] && b == -1)
        {
            c++ ;
            b = i ;
        }
        else if(arr[i]!=brr[i])
            c++ ;
    }
    if(a == b && a == -1){
        cout<<"YES"<<endl ;
    }
    else if(c<=2)
    {
        swap(brr[a],brr[b]);
        c=0 ;
        for(int i=0; i<n ; i++)
        {
            if(arr[i]!=brr[i])
                c++ ;
        }
        if(c==0)cout<<"YES"<<endl ;
        else cout<<"NO" <<endl  ;
    }
    else cout<<"NO" <<endl  ;


    return 0;
}

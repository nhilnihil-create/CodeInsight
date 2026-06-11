#include <bits/stdc++.h>
using namespace std ;
using ll=long long ;
int main(){
 int n , k ;
cin >> n >> k ;
int a[n];
for(int i=0 ; i< n ;i++)
{
    cin >>a[i] ;
}
sort(a+0,a+n) ;
ll sum =0 ;
for(int i=0 ; i<k ;i++)
{
    sum+=a[i] ;
}
cout << sum ;
 return 0 ;
}

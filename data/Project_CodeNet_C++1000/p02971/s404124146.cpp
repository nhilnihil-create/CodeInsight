#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main()
{  
    ll a1 , a2 ;
   
    ll N ;
    cin >> N ;
    ll a[N] ;
    ll b[N] ;
    for(ll i = 0 ; i < N ; i++){
        cin >> a[i] ;
        b[i] = a[i] ;
    }
    sort(a , a+ N) ;
    a1 = a[N-1] ;
    a2 = a[N-2] ;

    for(ll i = 0 ; i < N ; i++){
        if(b[i] == a1){
            cout << a2 << endl;
        }else{
            cout << a1 << endl;
        }
    }

    
    return 0;
}
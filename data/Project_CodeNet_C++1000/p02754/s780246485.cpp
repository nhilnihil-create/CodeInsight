#include<bits/stdc++.h>
#define int long  long 
#define ar array

using namespace std ;
                                                                                              
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;

    int n , a , b  ; 
    cin >> n >> a >> b  ; 
    int k = n/(a+b) ; 
    int r = n%(a+b) ; 
    cout << (k*a + min(r, a))  ;

                
}







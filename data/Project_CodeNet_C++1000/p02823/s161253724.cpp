#include <bits/stdc++.h>                                                          
#define rep(i,n) for (int i = 0; i< (n); i++)                                     
using ll = long long;                                                             
using namespace std;                                                              
                                                                                  
int main(){                                                                       
        ll N, A, B;                                                               
        cin >> N >> A >> B;                                                       
        ll ans;                                                                   
        if ((B-A)%2 == 0) ans = (B-A)/2;                                          
        else ans = min(A-1,N-B) + (B-A+1)/2;                                      
        cout << ans << endl;                                                      
                                                                                  
        return 0;                                                                 
}       
#include<bits/stdc++.h>

using namespace std ; 

const int N = 2e5 + 7 ;

int n; 
long long ans = 0 ; 


int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 
        //freopen("in.in" , "r" , stdin) ; 
        cin >> n; 

        for(int i = 0 ;i < n -1 ;i++){
                int u , v ; 
                cin >> u >> v; 
                if(u > v)
                        swap(u , v) ; 
                ans -= 1LL *  u * (n - v + 1LL) ; 
        }

        for(int i = 1; i<= n;i++){
                ans +=1LL * (i * (n - i + 1LL)) ; 
        }
        cout<< ans ; 

        return 0; 
}
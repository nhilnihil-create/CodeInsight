#include<bits/stdc++.h>

using namespace std  ; 

const int N = 3e3 + 7; 

int n , k , mod = 1e9 + 7 ; 
long long C[N][N];

void pre(){
        C[0][0] = 1ll ; 
        for(int i =1 ; i<N;i++){
                for(int j = 0 ;j <=i;j++){
                        if(!j || j ==i ){
                                C[i][j] = 1ll ; 
                        }
                        else{
                                C[i][j] = (C[i-1][j] + C[i-1][j-1]) %mod ; 
                        }
                }
        }
}

long long snb(long long x , long long y){
        if(x == y) return 1ll ; 
         x-=y ; 
         if(y - 1< 0 || x  < 0 )
                return 0ll ; 
         return C[x+y-1][y-1] ; 
}

int main(){
        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 
        pre() ; 
        cin>>n>>k ; 
        long long ans =1ll ; 
        for(int i = 1 ;i<=k;i++){
                long long mys = snb(k , i) ; 
                ans = (1ll * mys * snb(n - k  ,  i -1) ) %mod  ;
                if( i *2 <=n){
                        ans =ans +  2ll  * ( snb(n - k , i) * mys) %mod   ; 
                        ans%=mod ; 
                }
                if(i*2+1<=n){
                        ans = (ans + (snb(n - k , i+1) * mys)%mod ) %mod ; 
                }
                cout<<ans<<"\n" ;        
        }
        return 0; 
}
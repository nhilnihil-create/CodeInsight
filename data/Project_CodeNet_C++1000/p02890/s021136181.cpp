#include<bits/stdc++.h>

using namespace std ;

const int N =3e5 + 7 ; 

int  n , m ; 
int occ[N] ; 
vector<long long> v , v2 ; 

long long solve(int x){ 
        long long ret = 0 ; 

        int l = 1 , r = n ; 

        while(l<=r){
                long long mid = (l + r) >> 1 ; 
                long long deli = upper_bound(v.begin() , v.end() , mid ) - v.begin() ;
                long long gaz = (deli ? v2[deli - 1] : 0)  + ((int) v.size() - deli ) * mid ; 
                if(gaz>=mid * x){
                        l = mid+1 ; 
                        ret = mid ; 
                }
                else {
                        r = mid -1 ; 
                }
        }

        return ret ; 
}

int main(){

        ios_base::sync_with_stdio(0) ; 
        cin.tie(0) ; 

        cin >> n ; 

        for(int i = 0 ;i < n;i++){
                int x ;  
                cin >> x; 
                occ[x] ++ ; 
        }   
        for(int i = 0 ;i <= n;i++){
              v.push_back(occ[i]) ; 
              v2.push_back(0) ; 
        }
        sort(v.begin() , v.end()) ; 
        for(int i = 0 ;i <= n;i ++){
              if(i){
                    v2[i] = v2[i-1] ; 
              }
              v2[i] += v[i] ; 
        }
        v2.push_back(v2.back()) ;

       

        for(int i = 1 ;i <= n;i++){      
            cout<< solve(i) <<"\n" ; 
        }

        return 0; 
}
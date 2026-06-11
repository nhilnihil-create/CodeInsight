#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
   int M = max(a,b);
   int m = min(a,b);
   if(M%m == 0){
       return m;
   } 
   else{
       return gcd(M%m, m);
   }
}


int main(){
    int k;
    cin >> k;
    int ans=0;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            for(int l=1; l<=k; l++){
                ans += gcd(gcd(i,j), l);
            }
        }
    }
    cout << ans << endl;
}
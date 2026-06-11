#include<bits/stdc++.h>

using namespace std;  

int solvio1(int p){
     while (p >= 10) 
     p /= 10; 
     return p; 
} 
void solve(){ 
    int i,j,n;   
    cin >> n; 
    int tot[10][10] = {}; 
    for (i = 1; i <= n; i++) { 
        int pro1  = i % 10; 
        int pro = solvio1(i); 
        tot[pro][pro1]++; 
    } 
    int ans = 0; 
    for(i=0; i<10; i++)
    for(j=0;j<10;j++)
      ans = ans + tot[i][j] * tot[j][i];
      cout << ans << endl; 
} 

    
int main(){
    
    solve();
    return 0;
}

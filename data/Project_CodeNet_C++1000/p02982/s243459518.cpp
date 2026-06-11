#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,d;
    cin >> n >> d;
    
    int x[n][d];
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin >> x[i][j];
        }
    }
    
    int ans(0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            int rout(0);
            for(int k=0;k<d;k++){
                rout += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            
            bool judge(false);
            for(int k=0;k<=rout;k++){
                if(k*k == rout){
                    judge = true;
                }
            }
            
            if(judge){
                ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}

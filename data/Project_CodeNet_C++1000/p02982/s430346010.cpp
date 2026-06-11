/*
      author  : nishi5451
      created : 15.08.2020 11:08:39
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,d;
    cin >> n >> d;
    vector<vector<int>> x(n,vector<int>(d));
    rep(i,n){
        rep(j,d){
            cin >> x[i][j];
        }
    } 
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double dist = 0.0;
            for(int k=0; k<d; k++){
                dist += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            dist = sqrt(dist);
            if((dist-(int)dist) < 0.00001){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int> (d));
    rep(i, n)rep(j, d){
        cin >> x[i][j];
    } 
    double dist = 0;
    int cnt = 0; 
    rep(i, n){        
        for(int j = i + 1; j < n; j++){
            dist = 0;
            rep(k, d){
                dist += pow(x[i][k] - x[j][k], 2.0);
            }
            double ans = sqrt(dist);
            if(ceil(ans) != floor(ans)){
                continue;
            }else{
                cnt++;
            }
        }    
        
    }
    cout << cnt << endl;
    return 0;
}
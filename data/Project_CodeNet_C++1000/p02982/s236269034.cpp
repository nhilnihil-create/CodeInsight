#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 1e18LL

const ll MAX = 1000000000000000000; //1e18

int main(){
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i, n){
        rep(j, d){
            cin >> x[i][j];
        }
    }
    int LL = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int ans = 0;
            for(int k = 0; k < d; k++){
                ans += pow(x[i][k] - x[j][k], 2);
            }
            for(int k = 1; k*k <= ans; k++){
                if(k*k == ans) LL++;
            }
        }
    }
    cout << LL << endl;
}


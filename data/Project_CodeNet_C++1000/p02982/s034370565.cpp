#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;

int Ddim_dist(vector<int> y, vector<int> z){
    double dist = 0;
    int d = (int)y.size();
    for(int i=0; i<d; ++i){
        dist += pow((y[i] - z[i]),2); 
    }
    return dist;
}


int main(){
    int n,d;
    cin >> n >> d;
    vector<vector<int>> X(n,vector<int>(d));
    rep(i,n){
        rep(j,d){
            cin >> X[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int norm = Ddim_dist(X[i],X[j]);

            bool flag = false;
            for(int k=0; k<=norm; ++k){
                if(k*k==norm) flag=true;
            }
            if(flag) ans += 1;
        }
    }
    cout(ans);





    return 0;
}
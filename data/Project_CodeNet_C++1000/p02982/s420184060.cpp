#include <iostream>
#include<vector>
#include<cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;


int main() {
    int n, d;
    cin>>n>>d;
    vector<vector<int>>x(n,vector<int>(d));
    rep(i,n){
        rep(j,d) cin>>x[i][j];
    }
    int ans = 0;
    
    rep(i,n-1){
        rrep(k,n-i-1){
            double dist = 0;
            rep(j,d){
                dist += (x[i][j]-x[i+k][j])*(x[i][j]-x[i+k][j]);    
            }
            if((int)sqrt(dist)*(int)sqrt(dist)==(int)dist){
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
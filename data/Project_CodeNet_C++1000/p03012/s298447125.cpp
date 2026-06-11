#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n;
    cin >> n;
    int w[n];
    rep(i, n) cin >> w[i];
    int sm[n+1];
    sm[0] = 0;
    rep(i, n){
        sm[i+1] = sm[i] + w[i];
    }
    int ans = 1000000000;
    rep(i, n){
        // cout << sm[i] << " " << sm[n] - sm[i] << endl;
        ans = min(ans, abs(sm[i] - (sm[n] - sm[i])));
    }
    cout << ans << endl;
}
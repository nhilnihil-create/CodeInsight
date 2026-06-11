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

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    int b[n-1];
    rep(i, n-1) cin >> b[i];
    int ans = 0;
    rep(i, n){
        if(i == 0){
            ans += b[i];
        }else if(i == n - 1){
            ans += b[i-1];
        }else{
            ans += min(b[i], b[i-1]);
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}
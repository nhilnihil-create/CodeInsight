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
    int a[n], b[n], c[n-1];
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) cin >> b[i];
    rep(i, n-1) cin >> c[i];
    int ans = 0;
    int bef = -2;
    rep(i, n){
        ans += b[a[i]];
        if(bef + 1 == a[i]) ans += c[bef];
        bef = a[i];
    }
    cout << ans << endl;
}
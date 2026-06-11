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
    int l[n];
    rep(i, n) cin >> l[i];
    sort(l, l + n);
    ll ans = 0;
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            int idx = lower_bound(l, l + n, l[i] + l[j]) - l;
            idx--;
            ans += idx - j;
            // cout << idx << endl;
        }
    }
    cout << ans << endl;
}
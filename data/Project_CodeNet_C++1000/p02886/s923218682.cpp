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
    int d[n];
    rep(i, n) cin >> d[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++){
            ans += d[i] * d[j];
        }
    }
    cout << ans << endl;
}
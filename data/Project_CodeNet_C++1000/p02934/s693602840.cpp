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
    double a[n];
    rep(i, n) cin >> a[i];
    double ans = 0;
    rep(i, n) ans += (double)1 / a[i];
    ans = 1 / ans;
    printf("%.10lf\n", ans);
}
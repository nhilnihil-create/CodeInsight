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
    sort(d, d + n);
    int ans;
    if(d[n/2] == d[n/2-1]) ans = 0;
    else ans = d[n/2] - d[n/2-1];
    cout << ans << endl;
}
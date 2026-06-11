#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
    llong n,redcount=0,ans=0;
    char c[200100];
    cin >> n >> c;
    rep(i,n) if(c[i] == 'R') redcount++;
    
    rep(i,redcount) if(c[i] == 'W') ans++;
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;



int main() {
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    ll sum = 0;
    rep (i,n) cin >> a[i];
    rep (i,n) {
        cin >> b[i];
        sum += b[i];
    }
    rep (i,n-1) cin >> c[i];
    rep (i,n){
        if(a[i+1]-a[i]==1){
            sum += c[a[i]-1];
        }
    }
    cout << sum << endl;

}


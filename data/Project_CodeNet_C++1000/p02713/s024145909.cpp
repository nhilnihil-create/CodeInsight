#include<bits/stdc++.h>
using namespace std;
#define step(i, s, n, d) for(int i=s; i<n; i+=d)
#define FOR(i,s,n) step(i,s,n,1)
#define rep(i,n) FOR(i,0,n)
#define ll long long
typedef pair<int, int> P;

int aa(int a, int b, int c) {
    int res = 0;
    int m = min(a,min(b , c));
    FOR(i, 1, m + 1) {
        if(a % i == 0 && b % i == 0 && c % i == 0) {
            res = i;
        }
    }
    return res;
}


int main(){
    int n;
    ll result = 0;
    cin >> n;
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            FOR(k, 1, n+1) {
                result += aa(i, j, k);
            }
        }
    }
    cout << result << endl;
}
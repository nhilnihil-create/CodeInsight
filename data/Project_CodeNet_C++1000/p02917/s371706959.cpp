#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    vi b(n, 100001), a(n+1, 0);
    rep(i, n-1) cin >> b[i];
    
    a[0] = b[0];
    repa(i, 1, n){
        a[i] = min(b[i-1], b[i]);
    }

    int sum = 0;
    rep(i, n) sum += a[i];
    cout << sum << endl;
    return 0;
}
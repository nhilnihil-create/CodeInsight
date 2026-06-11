#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<int> c(n-1);
    rep(i,n-1) cin >> c[i];
    int sum = b[a[0]-1];
    for(int i = 1;i < n;i++){
        sum  += b[a[i]-1];
        if(a[i] == a[i-1]+1) sum += c[a[i-1]-1];
    }
    cout << sum << endl;
}
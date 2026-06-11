#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, k;

int main(void){
    cin >> n >> k;
    vector<lli> a(n);
    rep(i, n){
        cin >> a[i];
        a[i]--;
    }
    lli now = 0;
    lli c;
    lli d;

    if(k < 1e6){
        while(k > 0){
            now = a[now];
            k--;
        }
        cout << now+1 << endl;
        return 0;
    }
    vector<lli> seen(n, -1);
    seen[now] = 0;
    while(1){
        lli nx = a[now];
        if(seen[nx] != -1){
            c = seen[now]-seen[nx]+1;
            d = seen[nx];
            break;
        }
        seen[nx] = seen[now]+1;
        now = nx;
    }
    lli t = d + (k-d)%c;
    now = 0;
    while(t--){
        now = a[now];
    }
    cout << now + 1 << endl;
    return 0;
}

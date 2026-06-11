#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 100005
#define ll long long

void DBG() {
    cerr << "]\n";
}
template <class H, class... T> void DBG(H h, T... t) {
    cerr << h;
    if (sizeof...(t)) {
        cerr << ", ";
    }
    DBG(t...);
}
#define _DEBUG
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

int tt, n, m, k;
int mp[10][10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char x;
            cin>>x;
            mp[i][j] = x=='#';
        }
    }
    int ans = 0;
    for(int a = 0;a<1<<n;a++){
        for(int b = 0;b<1<<m;b++){
            int cnt = 0;
            for(int i = 0;i<n;i++){
                if((a>>i)&1)continue;
                for(int j = 0;j<m;j++){
                    if((b>>j)&1)continue;
                    cnt+=mp[i][j];

                }
            }
            ans+=cnt==k;
        }
    }
    cout<<ans;
    return 0;
}
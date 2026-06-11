#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
const ll mod = 1e9 + 7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
string S;
ll res = 1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    for(int i = 1; i <= N; i++) res = res * i % mod;
    int cnt = 0;
    for(int i = 0; i < 2 * N; i++){
        if((i & 1) ^ (S[i] != 'B')){
            res = res * cnt % mod;
            cnt--;
        }else{
            cnt++;
        }
    }
    if(cnt != 0) res = 0;
    cout << res << endl;
    return 0;
}
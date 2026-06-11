#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void MaxHeapify(vector<int> &a, int x, int h) {
    int l = 2*x;
    int r = 2*x+1;
    int large;
    if(l <= h && a[x] < a[l]) large = l;
    else large = x;
    if(r <= h && a[large] < a[r]) large = r;

    if(x != large) {
        swap(a[x], a[large]);
        MaxHeapify(a, large, h);
    }
}

int main(){
    int h;
    cin >> h;
    V<int> a(h+1);
    Rep(i,h) cin >> a[i];
    for(int i = h/2; i >= 1; i--) {
        MaxHeapify(a,i,h);
    }
    Rep(i,h) cout << " " << a[i];
    cout << endl;
}

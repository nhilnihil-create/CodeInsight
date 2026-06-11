#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int l[200005],r[200005];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> l,r;
    for(int i = 0 ; i < n && l.size() < k ; i++){
        if(s[i] == 'o'){
            l.push_back(i);
            i+=c;
        }
    }
    reverse(ALL(s));
    for(int i = 0 ; i < n && r.size() < k ; i++){
        if(s[i] == 'o'){
            r.push_back(n-1-i);
            i+=c;
        }
    }
    sort(ALL(r));
    vector<int> ans;
    for(int i=0;i<min(r.size(),l.size());i++){
        if(r[i] == l[i])ans.push_back(l[i]);
    }
    for(auto x:ans)cout << x + 1 << endl;
}
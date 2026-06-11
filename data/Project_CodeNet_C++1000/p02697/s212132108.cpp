#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pii;
typedef long long ll;
#define debug(x) cout << #x << "=" << x << endl;
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); cout << (i>0 ? " ":"") << v[i++]); cout << "\n"; return os;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n%2 == 0) n--;
    int i = 1, j = (n+1)/2;
    int q = 2;
    while(q--){
        while(i < j){
            cout << i << " " << j << "\n";
            i++;
            j--;
            m--;
            if(m == 0) break;
        }
        if(m == 0) break;
        if(n == 3) break;
        i = ((n+1)/2) + 1;
        j = n;
    }
    return 0;
}
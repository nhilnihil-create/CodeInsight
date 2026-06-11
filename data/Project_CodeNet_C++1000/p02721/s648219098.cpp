#include<bits/stdc++.h>
#define oo 1e9
#define endl '\n'
#define ll long long
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>


using namespace std;

int n, k, c;
vi L, R;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> c;
    cin >> s;
    L.pb(-oo);
    R.pb(oo);

    for(int i=0; i < n; ++i) {
        if(L.size() == k + 1) {
            break;
        }
        if(s[i] == 'x') continue;
        if(L.back() + c < i) {
            L.pb(i);
        }
    }

    for(int i=n - 1; i >= 0; --i) {
        if(R.size() == k + 1) {
            break;
        }
        if(s[i] == 'x') continue;
        if(R.back() - c > i) {
            R.pb(i);
        }
    }
    
    R.pb(-oo);
    L.pb(oo);

    reverse(R.begin(), R.end());

    for(int i=1; i < R.size() - 1; ++i) {
        //cout << R[i] << ' ' << L[i] << endl;
        if(R[i] == L[i]) {
            cout << R[i]+1 << endl;
        }
    }
    cout << endl;
    return 0;
}

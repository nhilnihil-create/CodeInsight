#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    
    ll sum = 0;
    vector<char> te(n);
    rep(i,n) {
        if(t[i] == 'r') {
            if(i >= k && te[i-k] == 'p') {
                if(i+k < n)
                    te[i] = t[i+k];
                else
                    te[i] = 'r';
            }
            else {
                te[i] = 'p';
                sum += p;
            }
        }
        else if(t[i] == 's') {
            if(i >= k && te[i-k] == 'r') {
                if(i+k < n)
                    te[i] = t[i+k];
                else
                    te[i] = 's';
            }
            else {
                te[i] = 'r';
                sum += r;
            }
        }
        else {
            if(i >= k && te[i-k] == 's') {
                if(i+k < n)
                    te[i] = t[i+k];
                else
                    te[i] = 'p';
            }
            else {
                te[i] = 's';
                sum += s;
            }
        }
    }
    
    cout << sum << endl;
    
    
    return 0;
}



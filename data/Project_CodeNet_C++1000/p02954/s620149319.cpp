#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n);
    bool isCheckingR = true;
    int rcount = 0;
    int lcount = 0;
    int i_lastR = 0;
    int odd_count = 0;
    int even_count = 0;
    rep(i,n){
        if(isCheckingR){
            if(s[i] == 'R'){
                rcount++;
            } else {
                i_lastR = i - 1;
                even_count += (rcount + 1) / 2;
                odd_count += rcount / 2;
                
                isCheckingR = false;
                lcount++;
            }
            if(i == n - 1){
                odd_count++;
                ans[i_lastR] = even_count;
                ans[i] = odd_count;
            }
        }
        else {
            if(s[i] == 'L'){
                lcount++;
            } else {
                odd_count += (lcount + 1) / 2;
                even_count += lcount / 2;
                rcount = 1;
                lcount = 0;
                isCheckingR = true;
                ans[i_lastR] = even_count;
                ans[i_lastR + 1] = odd_count;
                even_count = 0;
                odd_count = 0;
            }
            if(i == n - 1){
                odd_count += (lcount + 1) / 2;
                even_count += lcount / 2;
                ans[i_lastR] = even_count;
                ans[i_lastR + 1] = odd_count;
            }
        }
        // cout << "i: " << i << endl;
        // cout << "odd_count: " << odd_count << endl;
        // cout << "even_count: " << even_count << endl;
        // cout << "lcount: " << lcount << endl;
        // cout << "rcount: " << rcount << endl;
        // cout << "i_lastR: " << i_lastR << endl;

    }
    rep(i,n){
        cout << ans[i] << " "; 
    }
    cout << endl;
    return 0;
}

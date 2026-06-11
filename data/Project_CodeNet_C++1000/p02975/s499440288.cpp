#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    if(n % 3 == 0){
        map<int, int> mp;
        rep(i, n)mp[a[i]]++;
        if(mp.size() > 3){
            cout << "No" << endl;
            return 0;
        }
        int m = 0;
        for(auto p : mp){
            int cnt = p.second;
            if(cnt % (n/3) != 0){
                cout << "No" << endl;
                return 0;
            }
            m ^= p.first;
        }
        if(m == 0){
            cout << "Yes" << endl;
            return 0;
        }else{
            if(mp.size() == 2 && mp[0] == n/3){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }else{
        set<int> s;
        rep(i, n)s.insert(a[i]);
        if(s.size() == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
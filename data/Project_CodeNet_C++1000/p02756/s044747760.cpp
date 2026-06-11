#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int ord = 0;
    deque<char>ans;
    int n = (int)s.size();
    rep(i,n) ans.push_back(s[i]);
    rep(i,q) {
        int t;
        cin >> t;
        if(t==1) {
            ord ^= 1;
        }
        if(t==2) {
            int f;
            cin >> f;
            f--;
            char c;
            cin >>c;
            if((ord^f) ==0) {
                ans.push_front(c);
            }
            else {
                ans.push_back(c);
            }
        }

    }
    if(ord==1) {
        while(!ans.empty()) {
            char c = ans.back();
            ans.pop_back();
            cout << c;
        }
    } else {
        while(!ans.empty()) {
            char c = ans.front();
            ans.pop_front();
            cout << c;
        }
    }
    cout << endl;
}
    
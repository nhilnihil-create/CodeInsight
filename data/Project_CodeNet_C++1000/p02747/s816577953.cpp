#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}
int main(){
    string s; cin>>s;
    string ans = "Yes";
    if(s.length()%2) ans = "No";
    for(int i=0; i<s.length(); i+=2){
        if(s[i] != 'h' || s[i+1] != 'i') {
            ans = "No"; break;
        }
    }
    cout << ans << endl;
}
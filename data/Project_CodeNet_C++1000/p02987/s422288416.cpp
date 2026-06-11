#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;

int main(){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if(s[0]==s[1]&&s[2]==s[3]&&s[1]!=s[2])cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s;
    cin>>s;
    bool a=false,b=false,c=false;
    if(s[0]=='R') a=true;
    if(s[1]=='R') b=true;
    if(s[2]=='R') c=true;

    if(a&&b&&c) cout<<3<<endl;
    else if((a&&b)||(b&&c)) cout<<2<<endl;
    else if(a||b||c) cout<<1<<endl;
    else cout<<0<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000000000009
#define int long long
using P = pair<int,int>;

signed main(){
    string s;
    cin >> s;
    bool flag = true;
    rep(i,s.size()){
        if(i % 2 == 0){
            if(s[i] != 'h') flag = false;
        }
        else{
            if(s[i] != 'i') flag = false;
        }
    }
    if(s.size() % 2 == 0){
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
}
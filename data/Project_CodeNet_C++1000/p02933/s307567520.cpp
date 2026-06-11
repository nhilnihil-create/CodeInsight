#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;
const ll MOD = 1e9+7; int INF=INT_MAX; ll LLINF = 1LL << 60;
const vector<int> d8x = {1, 0, -1, 0, 1, -1, -1, 1}; vector<int> d8y = {0, 1, 0, -1, 1, 1, -1, -1};
const vector<int> d4x = {1, 0, -1, 0}; vector<int> d4y = {0, 1, 0, -1};

//

int main(){
    int a; cin>>a;
    string s; cin>>s;
    if(a>=3200){
        cout<<s<<endl;
    }else{
        cout<<"red"<<endl;
    }
}
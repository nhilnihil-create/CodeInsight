#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    string s,t;
    rep(i,a){
        s.push_back('0');
        t.push_back('1');
    }
    rep(i,w-a){
        t.push_back('0');
        s.push_back('1');
    }

    rep(i,b){
        cout << s << endl;
    }
    rep(i,h-b) cout <<t << endl;
}
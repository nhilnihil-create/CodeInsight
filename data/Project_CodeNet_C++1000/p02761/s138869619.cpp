#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> num(4);
    rep(i,m){
        int s, c;
        cin >> s >> c;
        if(s == 1 && c == 0 && n != 1){
            cout << -1 << endl;
            return 0;
        }
        if(num[s] == 0 || num[s] == c) num[s] = c;
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    if(num[1] == 0 && n != 1){
        num[1] = 1;
    }
    for(int i = 1; i <= n; i++) cout << num[i];
}
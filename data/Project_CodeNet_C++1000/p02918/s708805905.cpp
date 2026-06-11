#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    string t = "";
    bool flag;
    int cnt = 0;
    int Lcnt = 0;
    int Rcnt = 0;
        if(s[0]=='L') {
        flag = true;
        t.push_back('('); 
        Lcnt++;
    }else {
        flag = false;
        t.push_back(')');
        Rcnt++;
    }

    rep(i,n-1){
        if(flag){
            if(s[i+1]=='L') cnt++;
            else {
                t.push_back(')');
                Rcnt++;
                flag = false;
            }
        }else{
            if(s[i+1] == 'R') cnt++;
            else{
                t.push_back('(');
                Lcnt++;
                flag = true;
            }
        }
    }
    if(max(Lcnt,Rcnt) > k) cout << cnt + 2*k << endl;
    else cout << n-1 << endl;

}
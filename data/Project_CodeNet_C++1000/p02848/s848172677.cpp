#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int f(char s){
    int cnt = 0;
    string d = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    rep(i,d.size()){
        cnt++;
        if(d[i] == s)return cnt;
    }
    //return;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans = "";
    rep(i,s.size()){
        ans += alp[f(s[i])+n-1];
    }
    cout << ans;
}
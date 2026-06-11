#include<bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n;
    string s;
    cin >> n >> s;
    string s2;
    bool cnt = true;
    if(n == 1){cout << "No"; return 0;}
    if(n % 2 == 1){cout << "No" << endl; return 0;}
    
    rep(i, n/2){
        if(s[i] != s[i + n/2]){
            cnt = false;
        }
    }
    if(cnt){cout << "Yes" << endl;}
    else {cout << "No" << endl;}
    
}
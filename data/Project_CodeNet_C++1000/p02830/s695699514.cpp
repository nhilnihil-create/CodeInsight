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
    string s, t;
    cin >> n >> s >> t;
    rep(i, n){
        cout << s[i] << t[i];
    }
    return 0;
}
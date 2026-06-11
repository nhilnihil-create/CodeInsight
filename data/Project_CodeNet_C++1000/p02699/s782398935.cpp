#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s,w;
    cin >> s >> w;
    if(s>w)cout << "safe" << "\n";
    else cout << "unsafe" << "\n";
    return 0;
}
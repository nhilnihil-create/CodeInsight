#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;

    int ans = 0;
    if (S == "SUN")
    {
        ans = 7;
    } else if (S == "MON")
    {
        ans = 6;
    } else if (S == "TUE")
    {
        ans = 5;
    } else if (S == "WED")
    {
        ans = 4;
    } else if (S == "THU")
    {
        ans = 3;
    } else if (S == "FRI")
    {
        ans = 2;
    } else
    {
        ans = 1;
    }
    
    cout << ans << endl; 
  return 0;
}

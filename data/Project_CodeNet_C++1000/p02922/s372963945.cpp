#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    int a,b;
    cin >> a >>b;
    int ans = (b-1)/(a-1);
    if((b-1)%(a-1) != 0) ans++;

    cout << ans << endl;

}
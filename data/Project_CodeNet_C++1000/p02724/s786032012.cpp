#include <bits/stdc++.h>
#define rep(i,n) for(int i =0; i < (n); i++)
using namespace std;

int main(){
    int x;
    cin >> x;

    int y = x / 500;
    int z = x % 500;
    int a = z / 5;
    int ans = y*1000 + a*5;

    cout << ans << endl;

    return 0;
}
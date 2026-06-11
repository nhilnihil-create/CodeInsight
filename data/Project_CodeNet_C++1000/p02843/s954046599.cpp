#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int x;
    cin >> x;
    int k = x / 100;
    if(x >= 100 * k && x <= 105 * k)cout<< 1 << endl;
    else cout<< 0 << endl;
    return 0;
}
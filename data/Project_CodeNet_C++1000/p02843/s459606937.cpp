#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int x;
    cin >> x;
    int lim = x/100;
    if(lim*5 >= x%100) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define loop(i, n) for(int i = 0;i < n;i++)
#define IINF 2e9
#define MOD 1e9+7

int main(void){

    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;

    int t1 = h1*60 + m1;
    int t2 = h2*60 + m2;

    if(t2 - t1 < k) cout << 0 << endl;
    else cout << t2 - t1 - k << endl;


    return 0;
}
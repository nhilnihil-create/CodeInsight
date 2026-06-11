#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main(void){
    int x;
    cin >> x;

    cout << x * 360 / __gcd(x, 360) / x << "\n";

    return 0;
}

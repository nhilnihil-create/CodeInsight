#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#define ll long long
#define add push_back
using namespace std; 

int main() {

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;  t = 1; //cin >> t;
    while(t--){
        ll n; cin >> n;
        ll answ = 0;
        for(int i = 1; i <= n; i++){
            ll a1 = i;
            ll an = n - n % i;
            ll N = (an - a1) / i + 1;
            ll sn = ((a1 + an) * N) / 2;
            //cout << a1 << " " << an << " " << N <<" " << sn << endl;
            answ += sn;
        }
        cout << answ << endl;
    }
    return 0;
}
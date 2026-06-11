#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

ll mm[10][10];

int main(){
    ll n;
    cin >> n;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mm[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        string str = to_string(i);
        mm[str[0]-'0'][str[str.length()-1]-'0']++;
    }

    ll ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            ans += mm[i][j] * mm[j][i];
        }
    }

    cout << ans << endl;
    
    return 0;
}
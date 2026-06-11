#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>


using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBAG = false;

int money(int x){
    if(x == 3) return 100000;
    if(x == 2) return 200000;
    if(x == 1) return 300000;

    return 0;

}

int main(){

    int x, y;
    cin >> x >> y;

    int ans = 0;

    ans += money(x);
    ans += money(y);
    if(x == 1 && y == 1){
        ans += 400000 ;
    }

    cout << ans << endl;


}
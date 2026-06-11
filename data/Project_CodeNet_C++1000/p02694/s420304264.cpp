#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

void solve(){
    long long int x, money=100LL, year=1LL;
    cin >> x;
    while(true){
        money += money / 100;
        if(money >= x) break;
        year++;
    }
    cout << year << endl;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(16);
    
    solve();

    return 0;
}

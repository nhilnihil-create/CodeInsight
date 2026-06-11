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
    int k, a, b;
    cin >> k >> a >> b;
    string achieve = "NG";
    for(int i=a; i<=b; ++i){
        if(i % k == 0) achieve = "OK";
    }
    cout << achieve << endl;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(16);
    
    solve();

    return 0;
}

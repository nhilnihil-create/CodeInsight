#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(ceil(((double)a / d)) >= ceil(((double)c / b))) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(16);
    
    solve();

    return 0;
}

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
    int s, w;
    cin >> s >> w;
    if(s > w) cout << "safe" << endl;
    else cout << "unsafe" << endl;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(16);
    
    solve();

    return 0;
}

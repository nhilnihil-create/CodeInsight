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
    int n;
    string s;
    set<string> S;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> s;
        S.insert(s);
    }
    cout << S.size() << endl;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(16);
    
    solve();

    return 0;
}

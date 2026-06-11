// 173

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>

using namespace std;
using ll = long long int;
#define NUM 1000000007

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v.at(i);
    }
    sort(v.begin(), v.end(), greater<int>());
    auto itr = v.begin();
    for(int i=0; i<n; i++){
        ans += *itr;
        if(i%2 == 1) itr++;
    }
    ans -= *v.begin();
    cout << endl << ans << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
const ll INF = 1e18 + 1;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    int n;
    cin >> n;

    vector<int> vec(n);
    int all = 0;

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        all ^= vec[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << (all ^ vec[i]) << " ";
    }
    cout << endl;



}
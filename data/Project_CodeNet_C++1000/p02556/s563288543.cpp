#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(){
    int n;
    vector<int> v1, v2;
    int a, b, c, d;
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v1.push_back(x+y);
        v2.push_back(x-y);
    }
    // for_each(v1.begin(), v1.end(), [](int ele){cout << ele<< endl;});
    // for_each(v2.begin(), v2.end(), [](int ele){cout << ele<< endl;});
    int ans = max(*max_element(v1.begin(), v1.end()) - *min_element(v1.begin(), v1.end()), *max_element(v2.begin(), v2.end()) - *min_element(v2.begin(), v2.end()));
    cout << ans << endl;
}
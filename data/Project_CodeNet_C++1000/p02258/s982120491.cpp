#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n,0);
    for(auto&& x: v){
        cin >> x;
    }

    int ans = v[1] - v[0];

    int minv = v[0];

    for(int i=1; i<n; ++i){
        ans = max(ans, v[i] - minv);
        minv = min(minv, v[i]);
    }

    cout << ans <<endl;

    return 0;

}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];

    sort(h.begin(), h.end());

    while(k>0){
        if(h.empty()) break;
        h.pop_back();
        k--;
    }
    long long int ans = 0;

    for(int i=0; i<h.size(); i++){
        ans += h[i];
    }

    cout << ans << endl;
    return 0;
}
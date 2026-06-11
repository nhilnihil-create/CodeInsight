#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;


void solve(){
    int n, d, res = 0;
    cin >> n >> d;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i = 0; i < d; i++)
        res += arr[i];

    cout << res << endl;
  
}

int main()
{
    solve();
    return 0;
}
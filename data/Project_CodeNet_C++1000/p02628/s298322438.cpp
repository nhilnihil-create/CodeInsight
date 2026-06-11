#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
typedef long long ll;
using namespace std;

int arr[1007];
int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int res = 0;
    for (int i = 0; i < k; ++i) {
        res += arr[i];
    }
    cout << res << endl;



    return 0;
}

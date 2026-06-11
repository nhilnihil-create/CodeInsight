

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
    for (int i = 0; i <= n; ++i) {
        int a = n - i;
        int temp = i * 2 + a * 4;
        if (temp == k) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No" << endl;


    return 0;
}

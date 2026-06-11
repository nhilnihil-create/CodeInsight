#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
const int LIMIT = 1e6;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n), count(LIMIT + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }
    sort(a.begin(), a.end());
 
    vector<bool> divisible(LIMIT + 1);
    for (int i = 1; i <= LIMIT; i++) {
        if (count[i] > 0) {
            if (count[i] >= 2)divisible[i] = true;
            for (int j = i * 2; j <= LIMIT; j += i)divisible[j] = true;
        }
    }
 
    int ret = 0;
    for (auto x:a) {
        if (!divisible[x])ret++;
    }
    cout << ret << endl;
    return 0;
}
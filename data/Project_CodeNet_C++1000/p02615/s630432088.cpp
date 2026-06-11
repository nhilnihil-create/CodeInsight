#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    long long s = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < n-1; i++) {
        s += a[(i+1)/2];
    }
    cout << s << endl;
    return 0;
}
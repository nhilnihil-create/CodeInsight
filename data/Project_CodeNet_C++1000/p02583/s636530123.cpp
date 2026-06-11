#include <bits/stdc++.h>
using namespace std;
#define ll long long
void test_case()
{   
	int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    sort(a.rbegin(), a.rend());
 
    int count = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (a[i] < a[j] + a[k] && a[i] != a[j] && a[j] != a[k] && a[i] != a[k]) {
                    ++count;
                }
            }
        }
    }
 
    cout << count;
}

int main()
{
	test_case();
	return 0;
}

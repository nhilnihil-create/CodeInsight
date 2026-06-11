#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    int ans;
    for (int i=0;i<5;i++) {
        cin >> n;
        if (n == 0)
            ans = i+1;
    }
    cout << ans;
}
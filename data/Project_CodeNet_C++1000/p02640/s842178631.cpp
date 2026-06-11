#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n,m;
    cin >> n >> m;

    if (m&1) cout << "No";
    else {
        if (m > n*4 || m < n*2) cout << "No";
        else cout << "Yes";
    }
}
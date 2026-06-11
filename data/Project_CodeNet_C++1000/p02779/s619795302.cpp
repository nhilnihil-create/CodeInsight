#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 1; i < n; i++) if(a[i] == a[i - 1]) return cout << "NO\n", 0;
    cout << "YES";

    return 0;
}



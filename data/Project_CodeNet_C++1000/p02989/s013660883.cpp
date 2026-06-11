#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    int m1 = n/2-1;
    int m2 = n/2;

    cout << a[m2]-a[m1];
    return 0;
}
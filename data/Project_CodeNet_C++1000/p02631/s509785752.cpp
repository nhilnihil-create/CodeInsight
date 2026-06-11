#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int s = a[0];
    rep(i, n-1)
        s ^= a[i+1];
    rep(i, n){
        int bi = s^(a[i]);
        cout << bi;
        if(i == n-1) cout << endl;
        else cout << " ";
    }
    return 0;
}
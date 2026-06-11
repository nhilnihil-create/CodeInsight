// ABC163C.cpp

#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;
    int a[200005] = {};
    int x;
    for(int i=2;i<=n;i++){
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
}

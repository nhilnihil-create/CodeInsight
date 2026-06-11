#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            a[min(j-i, min(abs(x-i)+1+abs(y-j),abs(x-j)+1+abs(y-i)))]++;
        }
    }

    for(int i = 1; i < n; i++) {
        cout << a[i] <<  endl;
    }
    return 0;
}
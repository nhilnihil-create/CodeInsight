#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int k;
    long long h[200100];
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(h, h+n);
    long long total = 0;
    for(int i = 0; i < n-k; i++) total += h[i];
    cout << total << endl;
}
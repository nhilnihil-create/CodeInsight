#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    int cnt = 0;
    int index = 1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] != index) cnt++;
        else index++;
    }
    if(cnt == n) cnt = -1;
    cout << cnt << endl;
}
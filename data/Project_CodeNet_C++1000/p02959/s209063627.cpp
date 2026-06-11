#include <bits/stdc++.h>
using namespace std;

//n
int main() {
    int n;
    cin >> n;
    vector<long long>a(n + 1);
    vector<long long>b(n);
    for(int i = 0;i < n + 1;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
    }
    long long count = 0;
    for(int i = 0;i < n;i++){
        count += min(a[i],b[i]);
        b[i] -= min(a[i],b[i]);
        count += min(a[i + 1],b[i]);
        a[i + 1] -= min(a[i + 1],b[i]);
    }
    cout << count << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, s;
    cin >> n >> k >> s;

    vector<int> a(n);
    for(int i=0; i<k; i++) a[i] = s;
    for(int i=k; i<n; i++){
        if(s == 1e9) a[i] = s - 1;
        else a[i] = s + 1;
    }

    for(int i=0; i<n; i++){
        cout << a[i];
        if(i == n-1) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}
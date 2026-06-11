#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(n % 2 == 1){
        cout << b[n/2] - a[n/2] + 1 << endl;
    } else {
        cout << b[(n-1)/2] + b[(n-1)/2 + 1] - a[(n-1)/2] - a[(n-1)/2 + 1] + 1 << endl;
    }
    return 0;
}
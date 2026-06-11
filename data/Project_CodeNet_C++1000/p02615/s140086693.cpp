#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    long long int ans = 0;
    multiset<long long int> f = {a[0]};
    for(int i=1; i<n; i++){
        ans += *prev(f.end());
        f.erase(prev(f.end()));
        f.insert(a[i]);
        f.insert(a[i]);
    }
    cout << ans << endl;
    return 0;
}
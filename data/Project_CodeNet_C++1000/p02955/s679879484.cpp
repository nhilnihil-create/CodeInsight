#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0LL);
    set<int> s;
    for(int i = 1; i * i <= sum; i++)
        if(sum % i == 0){
            s.insert(i);
            s.insert(sum / i);
        }
    int ans = 1;
    for(int x : s){
        int p = 0;
        vector<int> r(n);
        for(int i = 0; i < n; i++)
            r[i] = a[i] % x;
        sort(r.begin(), r.end());
        int t = accumulate(r.begin(), r.end(), 0LL);
        int l = n - t / x;
        p = accumulate(r.begin(), r.begin() + l, 0LL);
        if(p <= k)
            ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}
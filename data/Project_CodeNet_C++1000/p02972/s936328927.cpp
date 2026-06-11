#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<n+1; i++) cin >> a[i];
    
    vector<int> ans(n+1);
    vector<int> b;
    
    for (int i=n; i>0; i--){
        int cnt = 0;
        for (int j=i; j < n+1; j+=i){
            if(ans[j]) cnt++;
        }
        
        // cout << cnt << endl;
        if(cnt % 2 == a[i]){}
        else {ans[i] = 1; b.push_back(i);}
        
    }
    cout << b.size() << endl;
    reverse(b.begin(), b.end());
    for (int x: b) cout << x << endl;
    
}

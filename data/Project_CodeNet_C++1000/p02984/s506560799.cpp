#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n),ans(n);
    long long even = 0,all = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        all += a[i];
        if(i % 2 == 1)even += a[i]; 
    }
    ans[0] = (all - even * 2) / 2;
    cout << ans[0] * 2 << " ";
    for(int i = 1;i < n;i++){
        ans[i] = a[i - 1] - ans[i - 1];
        cout << ans[i] * 2;
        if(i != n - 1)cout << " ";
        else cout << endl;
    }
}
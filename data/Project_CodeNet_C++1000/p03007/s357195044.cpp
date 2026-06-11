#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(n == 2){
        cout << a[1] - a[0] << endl;
        cout << a[1] << " " << a[0] << endl;
        return 0;
    }

    vector<pair<int,int>> operation;
    int ans = a[0];

    if(a[n-2] < 0){
        ans = a[n-1];
        for(int i=n-2; i>=0; i--){
            operation.push_back({ans, a[i]});
            ans = ans - a[i];
        }
    }
    else{
        bool flip = false;
        for(int i=n-2; i>=1; i--){
            if(flip == false && (a[i-1] <= 0 || i == 1)){
                operation.push_back({ans, a[i]});
                ans = ans - a[i];
                operation.push_back({a[n-1], ans});
                ans = a[n-1] - ans;
                flip = true;
            }
            else{
                operation.push_back({ans, a[i]}); 
                ans = ans - a[i];
            }
        }
    }
    cout << ans << endl;
    for(auto op : operation) cout << op.first << " " << op.second << endl;
    return 0;
}
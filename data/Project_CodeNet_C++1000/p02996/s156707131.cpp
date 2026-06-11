#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        a[i].first=y;
        a[i].second=x;
    }
    sort(a.begin(),a.end());
    ll sum=0;
    for(int i = 0; i < n; i++) {
        sum += a[i].second;
        if(sum>a[i].first){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
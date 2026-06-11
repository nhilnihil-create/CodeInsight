#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
    IOS;
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    int s = 0 , x = 0;
    for(int i = 0; i < n;i++){
        cin >> a[i];
        s += a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i = 0; i < n; i++){
        float u = 0.25 * 1/m * s;
        if(u > a[i])
            break;
        else
            x++;
    }
    if(x >= m){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}


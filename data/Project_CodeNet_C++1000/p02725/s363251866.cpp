#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int k,n;
    cin >> k >> n;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int ans = k;
    for(int i=1; i<n; i++){
        ans = min(ans, k-(vec[i]-vec[i-1]));
    }
    ans = min(ans,(vec[n-1]-vec[0]));
    cout << ans <<endl;
}
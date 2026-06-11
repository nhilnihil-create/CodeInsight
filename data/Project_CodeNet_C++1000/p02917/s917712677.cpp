#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    vector<int> vec;
    for(int i=0;i<n-1; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    int ans =0;
    vec[n-1] = INT32_MAX;
    for(int i=n-1; i>0; i--){
        ans += min(vec[i],vec[i-1]);
    }
    cout << ans+vec[0] <<endl;
}
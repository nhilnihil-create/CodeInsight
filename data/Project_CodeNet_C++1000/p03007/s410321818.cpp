#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    int neg = 0;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        v.push_back(a);
        if(a < 0)neg++;
    }
    sort(v.begin(), v.end());
    if(neg == 0) neg++;
    else if(neg == n)neg--;
    vector<pair<int, int>> ans;
    for(int i=neg;i<n-1;++i){
        ans.emplace_back(v[0], v[i]);
        v[0] -= v[i];
    }
    for(int i=0;i<neg;++i){
        ans.emplace_back(v.back(), v[i]);
        v.back() -= v[i];
    }
    cout << v.back() << endl;
    for(auto e: ans){
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long


int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > ans;
    int x;
    for(int i=1; i<=n; ++i){
        cin >> x;
        ans.push_back({x, i});
    }

    sort(ans.begin(), ans.end());

    for(auto z:ans)
        cout << z.second << " ";
}
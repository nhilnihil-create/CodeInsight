#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&& x:a)cin >> x;
    bool x = false;
     if(is_sorted(a.begin(), a.end()))x = true;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
        vector<int> b = a;
        swap(b[i], b[j]);
        if(is_sorted(b.begin(), b.end()))x = true;
    }
    cout << (x ? "YES" : "NO") << endl;
    return 0;
}

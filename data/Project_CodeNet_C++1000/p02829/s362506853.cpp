#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(2);
    for(auto&& v:a)cin >> v;
    sort(a.begin(), a.end());
    if(a[0] == 2)cout << 1 << endl;
    else if(a[1] == 2)cout << 3 << endl;
    else cout << 2 << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string a,b;
    string ans="";
    cin>>a>>b;
    for(int i=0;i<n;i++){
        ans.push_back(a[i]);
        ans.push_back(b[i]);
    }
    cout << ans<< endl;
    return 0;
}

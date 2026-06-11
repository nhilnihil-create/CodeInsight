#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin >> a;
    vector<int> v(a);
    for(int i=0;i<a;i++)cin >> v[i];
    sort(v.begin(),v.end());
    int x = v[a/2-1],y = v[a/2];
    cout << y-x << endl;
}

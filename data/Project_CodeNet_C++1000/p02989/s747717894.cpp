#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> d(n);
    for(int  &x: d) cin>>x;
    sort(d.begin(),d.end());
    cout<<d[n/2]-d[n/2-1]<<endl;
}
    

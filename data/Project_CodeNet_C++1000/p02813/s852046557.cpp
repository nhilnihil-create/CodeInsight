#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0,x,y;
    cin >> n;
    vector<int> v,p(n),q(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> q[i];
    for(int i=1;i<=n;i++) v.push_back(i);
    do{
        cnt++;
        if(v==p) x=cnt;
        if(v==q) y=cnt;
    }while(next_permutation(v.begin(),v.end()));
    cout << abs(x-y) << endl;
}
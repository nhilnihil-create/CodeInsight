#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,tmp=0,ans=1;
    cin >> n >> x;
    vector<int> l(n);
    for(int i=0;i<n;i++){
        cin >> l.at(i);
        tmp+=l.at(i);
        if(tmp<=x)ans++;
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    int n;
    string s,t;
    cin>>n>>s>>t;
    for(int i=0; i<n; i++){
        cout<<s[i]<<t[i];
    }
    cout<<endl;
    return 0;
}
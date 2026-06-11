#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    int n;
    string s, t, x = "";
    cin>>n>>s>>t;
    //int n = s.size();
    for(int i = 0; i<n; i++){
        x.push_back(s[i]);
        x.push_back(t[i]);
    }
    cout<<x<<"\n";
    return 0;
}
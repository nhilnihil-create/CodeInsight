#include "bits/stdc++.h"
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    
    long long sum=0;

    for(auto i : s)sum+=i-'0';
    if(sum%9)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}


#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int flag=1;
    string s,t;cin>>s>>t;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=t[i]) flag=0;
    }

    if(flag==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
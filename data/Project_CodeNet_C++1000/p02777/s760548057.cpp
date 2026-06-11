#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    string s,t;cin>>s>>t;
    int a,b;cin>>a>>b;
    string u;cin>>u;
    if(s==u) cout<<a-1<<" "<<b<<endl;
    else cout<<a<<" "<<b-1<<endl;

    return 0;
}
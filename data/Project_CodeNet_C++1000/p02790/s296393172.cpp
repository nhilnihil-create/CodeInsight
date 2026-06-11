#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int n,m; cin>>n>>m;
    if(n>m) for(int i=0; i<n; i++) cout<<m;
    else for(int i=0; i<m; i++) cout<<n;
    cout<<endl;


    return 0;
}
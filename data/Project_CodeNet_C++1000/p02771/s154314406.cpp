#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int a,b,c;cin>>a>>b>>c;
    int flag=0;

    if(a==b && b!=c) flag=1;
    if(b==c && c!=a) flag=1;
    if(c==a && a!=b) flag=1;

    if(flag==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
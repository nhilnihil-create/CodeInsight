#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int a,b,c,d;cin>>a>>b>>c>>d;
    if((a+d-1)/d < (b+c-1)/b) cout <<"No" <<endl;
    else cout<<"Yes"<<endl;

    return 0;
}
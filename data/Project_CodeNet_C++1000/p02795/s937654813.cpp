#include <bits/stdc++.h>
using namespace std;
int main(){int a,b,c;cin>>a>>b>>c;int d=max(a,b);if(c%d==0){cout << c/d << endl;return 0;}cout << (c/d)+1 << endl;}
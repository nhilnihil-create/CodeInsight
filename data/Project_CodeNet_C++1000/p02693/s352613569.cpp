#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int k,a,b;cin>>k>>a>>b;
    if(a/k!=b/k || a%k==0 || b%k==0) cout<<"OK"<<endl;
    else cout<<"NG"<<endl;



    return 0;
}
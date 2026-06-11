#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int n,m;cin>>n>>m;
    int sum=0;
    for(int i=0; i<n; i++) sum+=i;
    for(int i=0; i<m; i++) sum+=i;
    cout<< sum << endl;


    return 0;
}
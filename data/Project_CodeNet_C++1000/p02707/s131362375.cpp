#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e18
#define PI 3.141592653589793238
typedef long long ll;
#define N 200010

int main() {
    int n;cin>>n;
    int a[N];
    for(int i=0; i<n; i++) a[i]=0;
    for(int i=1; i<n; i++){
        int x;cin>>x;
        a[x-1]++;
    }
    for(int i=0; i<n; i++) cout<<a[i]<<endl;


    return 0;
}
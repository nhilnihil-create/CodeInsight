#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    int h,n;cin>>h>>n;
    int a[n], sum=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<h) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}
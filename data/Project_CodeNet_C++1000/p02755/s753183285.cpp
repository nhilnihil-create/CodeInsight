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
    int a,b;cin>>a>>b;
    int ans=1;
    while(ans<1010){
        if(floor(ans*0.08)==a && floor(ans*0.1)==b) break;
        ans++;
    }
    if(ans==1010)cout<<-1<<endl;
    else cout<<ans<<endl;


    return 0;
}
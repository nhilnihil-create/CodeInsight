#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

ll pow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*pow(x,n-1);
    return pow(x*x,n/2);
}

ll X;

int main(){
    cin>>X;

    ll A=0,B=0;
    for(ll i=-500;i<=500;i++){
        for(ll j=-500;j<=500;j++){
            if(pow(i,5)-pow(j,5)==X){
                A=i;
                B=j;
                break;
            }
        }
    }

    cout<<A<<' '<<B<<endl;
}
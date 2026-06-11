#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    ll a,bb,ans;
    float b;
    cin >> a >>b;
    b*=100;
  	b+=0.005;
    bb=b;
    ans=a*bb/100;
    cout << ans;
}
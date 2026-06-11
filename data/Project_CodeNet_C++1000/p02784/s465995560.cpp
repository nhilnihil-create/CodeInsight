#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll h, n;
    cin >> h >> n;
    int a;
    ll sum  = 0;
    for(int i=0; i<n; i++){
       cin >> a;
       h-=a;
    }
    if(h<=0)puts("Yes");
    else puts("No");

}
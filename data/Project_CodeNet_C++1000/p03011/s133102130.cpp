#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    int p,q,r;
    cin>>p>>q>>r;
    cout<<min(min(p+q,p+r),q+r);
    }
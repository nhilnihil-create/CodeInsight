#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<ll,ll>;
using vi = vector<ll>;
using vv = vector<vi>;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ta = (c+b-1)/b;
    int tb = (a+d-1)/d;
    if(ta<=tb)cout<<"Yes"<<endl;
    else      cout<<"No"<<endl;
    return 0;
}

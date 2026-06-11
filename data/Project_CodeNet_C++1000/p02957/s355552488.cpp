#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 100000000
const int MOD = 1000000007;


int main(){

    ll a,b;
    cin>>a>>b;
    if(a%2!=b%2)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<(a+b)/2<<endl;
    }
    return 0;
}
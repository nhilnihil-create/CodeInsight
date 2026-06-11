#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007
#define PI 3.1415


int main(){
    ll a,b,n;
    cin>>a>>b>>n;

    ll m = min(b-1,n);
    cout<<floor(a*m/b)-a*floor(m/b)<<endl;
}

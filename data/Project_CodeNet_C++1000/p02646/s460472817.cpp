#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 5;
const int maxm = 5e5 + 5;
const ll inf = 2147483647;

int main(){
    ll a, v, b, w, t;
    int f = 0;
    cin>>a>>v>>b>>w>>t;
    ll  d = abs(a - b);
    ll k = v - w;
    if(d <= k * t){
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}

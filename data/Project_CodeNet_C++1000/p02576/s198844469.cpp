#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll N,X,T;
    cin>>N>>X>>T;
    cout<<(ll)ceil((N*1.0/X*1.0))*T;
    return 0;
}

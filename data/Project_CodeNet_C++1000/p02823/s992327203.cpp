#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,a,b;
    cin>>n>>a>>b;
    if(a%2 == b%2)  {
        cout<<(b-a)/2;
    }
    else {
        cout<<min(a-1,n-b) + (b-a-1)/2 + 1;
    }
}
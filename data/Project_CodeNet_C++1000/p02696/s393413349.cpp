#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b,n,x;

int main() {
    cin >> a >> b >> n;
    x=min(n,b-1);
    cout <<(a*x)/b - a*(x/b);

}

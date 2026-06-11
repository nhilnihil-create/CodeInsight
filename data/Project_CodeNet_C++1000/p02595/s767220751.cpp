#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n , d;
    cin>>n>>d;
    int c = 0;
    for(int i=0;i<n;i++) {
        ll x1, x2;
        cin>>x1>>x2;
        double v = sqrt(pow(-x1, 2)+pow(-x2, 2));

        if(v <= d ) c++;
    }
    cout<<c<<endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll judge=a*a+b*b+c*c-2*a*b-2*b*c-2*c*a;
    if(judge>0&&c>a+b){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
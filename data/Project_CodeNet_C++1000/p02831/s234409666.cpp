#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
ll lcm(ll a, ll b)
{
    if (gcd(a,b) != 1) {
        return b * (a / gcd(a, b));
    }else{
        return b * a;
    }
}

int main() {
    ll A,B;
    cin >> A >> B;
    cout << lcm(A,B) << endl;
}

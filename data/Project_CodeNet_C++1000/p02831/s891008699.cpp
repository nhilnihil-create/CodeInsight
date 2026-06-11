#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

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
   return a * b / gcd(a, b);
}

int main(void){
    ll A; cin >> A;
    ll B; cin >> B;
    cout << lcm(A,B) << endl;
    return 0;
}
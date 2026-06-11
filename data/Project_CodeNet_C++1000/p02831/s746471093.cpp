#include <iostream>  
using namespace std;
typedef long long ll;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
ll gcd(ll a, ll b)  
{  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}  
 
ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
}  
 
int main()  
{  
    fast_io;
    ll a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;  
    return 0;  
} 
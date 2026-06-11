#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a != b && b != c && c != a || a == b && b == c && c == a){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(in) in.begin(), in.end()
#define FIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int, int> PII;

int main(){
    FIO;
    ll n;
    cin >> n;
    if( (n&(n-1)) == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << 1 << " " << 2 << endl;
    cout << 1 << " " << 3 << endl;
    cout << 2 << " " << n+3 << endl;
    cout << 3 << " " << n+2 << endl;
    cout << n+1 << " " << n+2 << endl;
    if(n == 3){
        return 0;
    }
    for(ll i = 4 ; i < n ; i += 2){
        ll x = i, y = i+1;
        cout << 1 << " " << x << endl;
        cout << 1 << " " << y << endl;
        cout << x << " " << n+y << endl;
        cout << y << " " << n+x << endl;
    }
    if(n%2 == 0){
        ll x = 1;
        while((1<<x) <= n){
            x++;
        }
        x = (1 << (x-1));
        ll x1 = 1^x^n;
        cout << x << " " << n << endl;
        cout << x1 <<  " " << n*2 << endl;
    }
    return 0;
}

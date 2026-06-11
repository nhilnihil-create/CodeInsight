#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
int main(){
    ll n, a, b;
    cin  >> n >> a >> b;
    if((b-a) % 2 == 0){
        cout << (b-a)/2 << endl;
    }else{
        if((n-b)>= (a-1)){
            ll aa = 1;
            ll bb = b - a-1 + 1;
            cout << a - 1 + 1 + (bb - aa)/2 << endl;
        }else{
            ll bb = n;
            ll aa = a + n - b + 1;
            cout << n - b + 1 + (bb-aa)/2 << endl;
        }
    }
}

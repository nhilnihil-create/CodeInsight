#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////


int main(){
    ll a,b;
    cin >> a >> b;
    if(a<b)swap(a,b);
    ll A = a, B = b, r;
    r = A % B;
    while(r!=0){
        A = B;
        B = r;
        r = A % B;
    }
    cout << a * b / B << endl;
}
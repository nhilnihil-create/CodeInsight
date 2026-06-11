#include <iostream>
#include <set>
typedef long long ll;
using namespace std;
ll gcd(ll a, ll b) {
    if (a%b == 0) {
        return b;
    } else {
        return gcd(b, a%b);
    }
}
int main() {
    ll a, b;
    cin >> a >> b;
    //a,bの最大公約数を素因数分解し、素因数の種類を数えれば良い
    ll g = gcd(a, b);
    ll i = 2;
    set<ll> st; //同じ素因数は重複して数えなくて良いのでsetを用いる
    st.insert(1);
    //a,b<=10^12より、10^6より大きい因数は2つ以上含まれないため
    //i=10^6で打ち切ればgは「1」か「10^6より大きい素因数」となる
    while (g > 1 && i <= 1000000) {
        if (g%i == 0) {
            g /= i;
            st.insert(i);
        } else {
            i++;
        }
    }
    st.insert(g);
    cout << st.size() << endl;
}
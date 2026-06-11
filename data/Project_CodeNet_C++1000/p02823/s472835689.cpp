#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
        return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
        ll n, a, b;
        cin >> n >> a >> b;

        if ((b - a) % 2 == 0) {
                cout << (b - a) / 2 << endl; 
        } else {
                cout << min(a+(b-a-1)/2, n-b+(b-a-1)/2+1) << endl;
        }

        return 0;
}

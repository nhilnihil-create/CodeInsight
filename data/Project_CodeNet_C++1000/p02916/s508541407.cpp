#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n){
        cin >> a.at(i);
        a.at(i)--;
    }
    rep(i, n){
        cin >> b.at(i);
    }
    rep(i, n-1){
        cin >> c.at(i);
    }
    int sum = 0;
    vector<int> vec_c;
    rep(i, n) sum += b.at(i);
    int x = a.at(0);
    for(int i = 1; i < n; i++){
        if(x == a.at(i)-1) vec_c.push_back(c.at(x));
        x = a.at(i);
    }
    int sum_c = 0;
    rep(i,vec_c.size()) sum_c += vec_c.at(i);
    cout << sum + sum_c << endl;

    return 0;
}

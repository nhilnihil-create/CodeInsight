#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
vector<long long> ll_vec(int n) {
    vector<long long> vec(n);
    for (int i=0; i<vec.size(); i++) cin >> vec.at(i);
    return vec;
}
void PA(vector<long long> vec) {
    for (int i=0; i<vec.size()-1; i++) cout << vec.at(i) << " ";
    cout << vec.at(vec.size()-1) << endl;
    return;
}
map<long long, long long> CL(vector<long long> vec) {
    map<long long, long long> count;
    for (long long x: vec) {
        count[x] += 1;
    }
    return count;
}



int main() {
    using ll = long long;
    using vl = vector<long long>;

    ll n; cin >> n;

    ll low = 1;
    for (ll i=2; i*i<n+1; i++) {
        if (n%i == 0) {
            low = i;
        }
    }


    ll high = n/low;
    ll ans = low + high -2;

    cout << ans << endl;

}

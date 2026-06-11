#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll ans = 0;
vector<ll> v;

void sliding_window(string s) {
    int left = 0, right = 0;
    while(left < s.size()) {
        while(right+1<s.size() && s[left]==s[right+1]) {
            right++;
        }
        v.push_back(right-left+1);
        left = right+1;
        right = left;
    }
}

ll sol(string s, int n, ll k) {
    if(n==1) {  // only 1 char in string
        ans = k/2;  // works for length of T is even and odd
        return ans;
    }
    if(n==v[0]) {
        return (k*n)/2;
    }
    // each v[i] is the number of same consecutive letters
    for(ll i=0; i<v.size(); i++) {
        ans += v[i]/2;
    }
    ans *= k;

    if(s[0]==s[n-1] && v[0]%2!=0 && v[v.size()-1]%2!=0) {    // odd occurences
        ans+=k-1;
    }
    return ans;
}

int main() {
    string s;
    int n;
    ll k;
    cin >> s >> k;
    n = s.size();

    sliding_window(s);
    cout << sol(s, n, k) << endl;
}
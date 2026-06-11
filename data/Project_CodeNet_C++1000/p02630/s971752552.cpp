#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#define ll long long
#define add push_back
 
using namespace std; 


int main() {

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;  t = 1; //cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v(n);
        map<ll,int> freq;
        ll curr = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            curr += v[i];
            freq[v[i]]++;
        }
        ll q; cin >> q;
        while(q--){
            ll a,b; cin >> a >> b;
            ll dif = b - a;
            curr += dif * freq[a];
            freq[b] += freq[a];
            freq[a] = 0;
            cout << curr << endl;
        }
    }
    return 0;
}
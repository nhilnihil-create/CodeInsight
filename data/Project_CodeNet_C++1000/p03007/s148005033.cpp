#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
   

    ll n;
    cin >> n;
    vector <ll> v;
    ll cntP = 0;
    ll cntN = 0;
    ll ans = 0;
    for (ll i=0;i<n;i++){
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
        ans += abs(tmp);
        if(tmp > 0)cntP++;
        if(tmp < 0)cntN++;
    }
    sort(v.begin(), v.end());
    if(cntN == 0){
        ans -= 2*v[0];
    }else if(cntP == 0){
        ans += 2*v[n-1];
    }
    cout << ans << endl;
    ll t = v[0];
    for (ll i=n-2;i>0;i--){
        if(v[i] >= 0){
            cout << t << " " << v[i] << endl;
            t = t - v[i];
        }else{
            break;
        }
    }
    cout << v[n-1] << " " << t << endl;
    t = v[n-1] - t;
    for (ll i=1;i<n-1;i++){
        if(v[i] < 0) {
            cout << t << " " << v[i] << endl;
            t = t - v[i];
        }
    }
}
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
    vector <string> slis;
    vector <ll> tlis;
    for (ll i=0;i<n;i++){
        string s;
        ll t;
        cin >> s >> t;
        slis.push_back(s);
        tlis.push_back(t);
    }
    string x;
    cin >> x;
    ll ans = 0;
    bool flag = false;
    for (ll i=0;i<n;i++){
        if(flag){
            ans += tlis[i];
        }
        if(slis[i] == x){
            flag = true;
        }
    }
    cout << ans << endl;
}
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
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
   

    ll n,k;
    cin >> n >> k;
    vector <ll> a, p(n);

    for(ll i=0;i<n;i++){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    ll q = 0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(a[i] > a[j]){
                q++;
                p[i]++;
            }else if(a[i] < a[j]){
                p[j]++;
            }
        }
    }
    ll ans = 0;
//    cout << q << endl;
    q %= mop;
    ans = k*q%mop;
    for(ll i=0;i<n;i++){
//        cout << p[i] << endl;
        ans += k*(k-1)/2 % mop * p[i] % mop;
        ans %= mop;
    }
    cout << ans%mop << endl;



}
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long
#define llv vector<long long>
#define assign_max(into, compared) (into = max((into), (compared)))
#define assign_min(into, compared) (into = min((into), (compared)))
#define rep(i,n) for(long long i = 0;i < n;i++)

using namespace std;

int main(void){
    ll x;
    cin >> x;
    llv v (100000+1,0);
    v[0] = 1;
    rep(i,100001){
        if(v[i] == 1){
            for(int j = 100;j <= 105 && i+j <= 100000;j++){
                v[i+j] = 1;
            }
        }
    }

    if (v[x] == 1)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
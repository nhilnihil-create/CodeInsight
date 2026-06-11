#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> vec(n);

    rep(i,n){
        cin>> vec[i];
    }
    sort(vec.begin(),vec.end(),less<ll>());
    
    ll sum = 0;
    rep(i,n-1){
        sum += vec[(n-1)-((i+1)/2)];
    }

    cout << sum << endl;
    return 0;
}
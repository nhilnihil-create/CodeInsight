#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> d(n+1,0);
    rep(i,n) cin >> d[i+1];
    sort(d.begin(),d.end());

    cout << d[n/2+1] - d[n/2]  << endl;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
int main() {

    int n;
    cin >> n;
    vector<float> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());

    float sum;

    rep(i,n-1){
        sum = (v[i+1]+v[i])/2;
        v[i+1] = sum;
    }

    cout << sum << endl;

    return 0;

}
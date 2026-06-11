#include <bits/stdc++.h>
#include <string>

using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
#define rep(i,n) for(int i = 0;i<n;i++)

int main(){

    int N, K;
    cin >> N >> K;
    vector<int> ar(N);

    rep(i,N)cin >> ar[i];

    sort(ar.begin(),ar.end());
    int sum= 0;
    rep(i,K)sum+=ar[i];
    cout << sum << endl;


}


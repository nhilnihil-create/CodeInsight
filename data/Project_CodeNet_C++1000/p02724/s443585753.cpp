#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    // Your code here!
    ll x;
    cin >> x;
    ll ans = x / 500;
    x -= 500*ans;
    ll ans2 = x / 5;
    ll happy = 1000*ans + ans2*5;
    cout << happy  << endl;
    return 0;
}
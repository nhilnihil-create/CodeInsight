#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
char in[120];
pair<pair<string,int>,int> p[110];

int gcd(int a, int b){
    if(b == 0){return a;}
    return gcd(b, a % b);
}

int main(){
    int n; cin >> n;
    ll sum = 0;
    ll ans1, ans2;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                ans1 = gcd(i, j);
                ans2 = gcd(ans1, k);
                sum += ans2;
            }
        }
    }
    cout << sum << endl;
}
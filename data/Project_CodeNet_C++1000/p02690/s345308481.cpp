#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int x;
    cin >> x;
    for(ll i = -200;i <= 200;i++){
        for(ll j = -200;j <= 200;j++){
            ll a = i*i*i*i*i;
            ll b = j*j*j*j*j;
            if(a - b == x){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int main(){
    ll n;cin >> n;
    bool a = false;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(i * j == n){
                a = true;
                break;
            }
        }

    }
    if(a){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}
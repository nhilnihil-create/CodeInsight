#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int a, b;
    cin >> a >> b;
    if(a < b){
        int ans = 0;
        for(int i = 0; i < b; i++){
            ans*=10;
            ans+=a;
        }
        cout << ans << endl;
    }else{
        int ans = 0;
        for(int i = 0; i < a; i++){
            ans*=10;
            ans+=b;
        }
        cout << ans << endl;
    }
}

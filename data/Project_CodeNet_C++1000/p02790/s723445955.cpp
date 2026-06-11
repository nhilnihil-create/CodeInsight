
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a, b;
    cin >> a >> b;
    if(a<b){
        for(int i=0; i<b; i++){
            cout << a;
        }     
    }
    else if(a>=b){
        for(int i=0; i<a; i++){
            cout << b;
        }
    }
}
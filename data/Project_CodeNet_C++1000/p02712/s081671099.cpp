
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){

    ll n;
    cin >> n;
    ll res=0;
    for(int i=1; i<=n; i++){
        if(i%3!= 0 && i%5!= 0){
            res += i;
        }
    }
    cout << res << endl;
   

}
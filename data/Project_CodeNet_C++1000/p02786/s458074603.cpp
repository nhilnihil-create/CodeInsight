
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll h;
    cin >> h;
    //hを超えない2の累乗で一番大きい数を探す
    ll near2 = 1;
    while(true){
        if(near2 > h){
            near2 /= 2;
            break;
        }
        else near2 *= 2;
    }

    ll sum=0;
    while(near2 > 0){
        sum += near2;
        near2 /= 2;
    }
    cout << sum << endl;




}
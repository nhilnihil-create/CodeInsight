
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while(true){
        c -= b;
        if(c <= 0){
            cout << "Yes" << endl;
            return 0;
        }
        a -= d;
        if(a <= 0){
            cout << "No" << endl;
            return 0;
        }
    }

   

}
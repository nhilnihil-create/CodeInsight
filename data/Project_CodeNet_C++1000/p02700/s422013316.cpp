#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main() { 
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int i = 1;; i++){
        if(i%2==1){
          C -= B;
          if(C<=0){
              cout << "Yes" << endl;
              return 0;
          }
        }
        else{
            A-=D;
            if(A<=0){
                cout << "No" << endl;
                return 0;
            }
        }
    } return 0;
}
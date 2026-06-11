#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    ll A , B;
    cin >> A >> B;
    ll N = gcd(A , B) , j = 1;
    for(ll i = 2; i * i < N; i++){
        if(N % i == 0){
            for(; N % i == 0; N /= i){
                
            }
            j++;
        }
    }
    if(N != 1){
        j++;
    }
    cout << j << endl;
}

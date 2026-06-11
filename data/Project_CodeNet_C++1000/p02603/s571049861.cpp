
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main(void){
    ll N,money = 1000,stock = 0;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A.at(i);
    }
    rep(i,N-1){
        if(A.at(i)<A.at(i+1)){
            money += (A.at(i+1)-A.at(i))*(money/A.at(i));
        }
    }
    cout << money << endl;
}
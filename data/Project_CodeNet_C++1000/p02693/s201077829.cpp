#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int A, K, B;
    cin >> K;
    cin >> A >> B;
    int i;
    for(i=A;i<=B;i++){
        if(i % K == 0){cout << "OK" << endl; return 0;}
    }
    cout << "NG" << endl;

    return 0;
}

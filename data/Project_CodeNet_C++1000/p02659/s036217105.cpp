#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    unsigned long long A;
    float B;
    int b;

    cin >> A >> B;
    
    b = static_cast<int>(B * 100 + 0.5);

    cout << (A * b )/ 100 << endl;

    return 0;
}

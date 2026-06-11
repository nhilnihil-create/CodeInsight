#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    ll N, A, B;
    cin >> N >> A >> B;

    ll amari;
    ll sho;
    
    sho   = N / (A + B);
    amari = N % (A + B);

    ll count = 0;

    count += sho * A;
    if(amari <= A){count += amari;}
    else{count += A;}

    cout << count << endl;

    return 0;
}

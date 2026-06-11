#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    ll ti=N/(A+B);
    cout << ti*A+min(A,N-ti*(A+B)) << endl;



    return 0;
}
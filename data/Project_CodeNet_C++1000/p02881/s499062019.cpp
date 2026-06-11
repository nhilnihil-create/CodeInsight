#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <tuple>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> P;


int main(){
    ll N;
    cin >> N;
    ll ans=N-1;
    for(ll i=2; i<=sqrt(N); i++){
        if(N%i!=0) continue;
        ll tmp=N/i;
        ans=min(ans,tmp+i-2);
    }
    cout << ans << endl;

    return 0;
}
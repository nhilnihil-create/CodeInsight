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
    ll X;
    cin >> X;
    unsigned long long money=100;
    unsigned long long ans=0;
    while(money<X){
        money+=money/100;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
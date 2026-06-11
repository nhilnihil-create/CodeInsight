#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include<numeric>
using namespace std;
using P = pair<int, int>;
#define rep(i,n) for(int i=0; i<(n);i++)
typedef long long ll;


int main(){
    ll x; cin >> x;
    ll d=100;
    ll ans=0;
    while(d < x){
        ll interest = d / 100;
        d += interest;
        ans++;
    }
    cout << ans << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll inf=1000000000000000000;

int main(){
    int n; cin >> n;
    ll ans=1;
    vector<ll> a(100100);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]==0){
            cout << "0\n";
            return 0;
        }
    }
    for(int i=0; i<n; i++){
        if(a[i]<=inf/ans){
            ans *= a[i];
        }else{
            ans = -1;
            break;
        }
    }
    cout << ans << "\n";
}
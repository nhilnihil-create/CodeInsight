#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int x,n; cin >> x >> n;
    vector<int> v(102,1);
    for(int i=0; i<n; i++){
        int p; cin >> p;
        v[p] = 0;
    }
    int ans=1e7;
    for(int i=0; i<102; i++) if(v[i]==1) if(abs(x-i)<abs(x-ans)) ans=i;
    cout << ans << "\n";
    return 0;
}
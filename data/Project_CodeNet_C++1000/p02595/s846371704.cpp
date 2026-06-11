#include <iostream>
using namespace std;

int main(){
    int n,ans=0;
    long long d;cin >> n >> d;
    d = d*d;
    for(int i=0; i<n; i++){
        long long x,y;cin >> x >> y;
        if(d>=x*x+y*y) ans++;
    }
    cout << ans << endl;
}
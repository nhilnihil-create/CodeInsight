#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n, d;
    cin >> n >> d;
    long long mx = d*d;
    int ns = 0;
    while(n--){
        long long x, y; cin >> x >> y;
        long long dist = x*x + y*y;
        if(dist<=mx){
            ns++;
        }
    }
    cout << ns;
    return 0;
}

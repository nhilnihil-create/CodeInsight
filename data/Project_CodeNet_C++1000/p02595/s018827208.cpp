#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n, d;
    cin >> n >> d;
    long long int x[n], y[n];
    int ans = 0;
    for (int i = 0; i < n; ++i){cin >> x[i] >> y[i];}
    for (int i = 0; i < n; ++i){
        if(x[i]*x[i]+y[i]*y[i] <= d*d){
            ++ans;
        }
    }
    cout << ans << endl;
}

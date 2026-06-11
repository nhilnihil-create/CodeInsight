#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int x;
    vector<long double> A(N);
    long double ans=0;
    for(int i=0; i<N; i++){
        cin >> x;
        ans += (long double)1.0/x;
    }
    
    ans = 1/ans;
    cout << fixed << setprecision(7) << ans << endl;
}
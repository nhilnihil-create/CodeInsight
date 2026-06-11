#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i=0;i<N;i++) {
        cin >> X[i];
    }
    
    ll ans=10000000000;
    for (int i=1;i<101;i++) {
        ll sum=0;
        for (int j=0;j<N;j++) {
            sum+=pow((X[j]-i),2);
        }
        ans=min(ans,sum);
    }
    
    cout << ans << endl;
}

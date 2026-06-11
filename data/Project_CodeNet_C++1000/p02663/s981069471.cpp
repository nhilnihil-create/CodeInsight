#include <bits/stdc++.h>
using namespace std;

int main(){
    int H1,M1,H2,M2,K; cin>>H1>>M1>>H2>>M2>>K;
    int t1 = H1*60+M1;
    int t2 = H2*60+M2;
    int ans = max( t2-K-t1  ,0);
    cout << ans << "\n";
}
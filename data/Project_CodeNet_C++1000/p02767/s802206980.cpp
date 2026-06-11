#include <bits/stdc++.h>
using namespace std;
int health(int P,int X){
    return (P-X)*(P-X);
}
int main(void){
    int N,X[101];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> X[i];
    }
    int L=X[0],R=X[0];
    for(int i=0;i<N;i++){
        L=min(L,X[i]);
        R=max(R,X[i]);
    }
    int ans=1000000000;
    int cost;
    for(int i=L;i<=R;i++){
        cost=0;
        for(int j=0;j<N;j++){
            cost+=health(i,X[j]);
        }
        ans=min(ans,cost);
    }
    cout << ans;
}
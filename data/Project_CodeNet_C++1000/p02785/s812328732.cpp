#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int N,K;
    cin >> N >> K;
    long long int Health[N];
    for(int i=0;i<N;i++) cin >> Health[i];
    sort(Health,Health+N);
    long long int ans=0;
    for(int i=0;i<N-K;i++){
        ans+=Health[i];
    }
    cout << ans;
}
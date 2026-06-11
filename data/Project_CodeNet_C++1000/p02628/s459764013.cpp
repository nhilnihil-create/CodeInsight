#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int p[1000];
    rep(i, N) cin >> p[i];

    sort(p, p+N);
    int sum=0;
    rep(i, K) sum+=p[i];

    cout << sum << endl;
}
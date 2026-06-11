#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int K, N;
    cin >> N >> K;
    vector<LL> p(N);
    REP(i,N)cin>>p[i];

    priority_queue<double> que;
    double sum = 0;
    REP(i,K){
        sum += (p[i] + 1) * 0.5;  
    }
    que.push(sum);

    for(int j=1; j+K-1<N; j++){
        sum -= (p[j-1] + 1) * 0.5;
        sum += (p[j+K-1] + 1) * 0.5;
        que.push(sum);
    }

    double ans = que.top();

    cout << fixed << setprecision(7) << ans << endl;
    
}
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,D,A;
P X[200001];
queue<P> range;
ll ans;
ll m;
ll K;



int main(){
    cin >> N>>D>>A;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        X[i] = P(a,b);
    }
    sort(X,X+N);
    
    for(int i=0;i<N;i++){
        while(range.size()!=0&& range.front().first<X[i].first){
            m -= range.front().second;
            range.pop();
        }
        if( X[i].second<m){
            X[i].second = 0;
        } else {
            X[i].second -= m;
        }
        K = (X[i].second+A-1)/A;
        range.push(P(X[i].first+2*D,K*A));
        m += K*A;
        ans += K;
    }
    cout << ans << endl;
    
}



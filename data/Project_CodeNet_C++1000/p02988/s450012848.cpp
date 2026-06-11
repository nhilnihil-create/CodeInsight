#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
    ll N,count=0;
    cin >> N;
    vector<ll> data(N);
    rep(i,N){
        cin >> data.at(i);
    }
    for(int i=1; i<=N-2; i++){
        ll a=max(data.at(i),max(data.at(i-1),data.at(i+1)));
        ll b=min(data.at(i),min(data.at(i-1),data.at(i+1)));
        if(data.at(i)!=a && data.at(i)!=b) count++;

    }

    cout << count << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
    ll N,K,count=0;
    cin >> N >> K;
    vector<ll> data(N);
    rep(i,N){
        cin >> data.at(i);
        if(data.at(i)>=K) count++;
    }

    cout << count << endl;
    
 
}
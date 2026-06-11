#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< pair<ll,ll> > prime_factorize( ll N ){
    vector< pair<ll,ll> > res;
    for(ll i = 2 ; i * i <= N ; i++){
        if(N % i != 0) continue;
        
        ll cnt = 0;
        while(N % i == 0){
            N /= i;
            cnt++;
        }
        res.push_back( make_pair(i,cnt) );
    }
    
    if(N != 1){
        res.push_back( make_pair(N,1) );
    }
    return res;
}


int main(void){
    ll N;
    cin >> N;
    vector< pair<ll,ll> > res = prime_factorize(N);
    
    ll cnt = 0;
    for(int i = 0 ; i < res.size() ; i++){
        for(int j = 1 ; j <= res.at(i).second ; j++){
            
            ll tmp = pow( res.at(i).first , j );
            if(N % tmp == 0){
                N /= tmp;
                cnt++;
            }
            
            if(N < tmp) break;
        }
    }
    cout << cnt << endl;
}

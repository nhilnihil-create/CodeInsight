#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n; cin >> n;
    vector<ll> v;
    for(ll i=1; i*i<=n; ++i){
        if(n%i==0){
            v.push_back(i);
            if(n/i!=i){v.push_back(n/i);}
        }
    }
    sort(v.begin(), v.end());
  	//for(int i=0; i<v.size(); ++i){cout << v[i] << ",";} cout << endl;
    ll res; 
    if(v.size()%2==1){
        ll d = (v.size())/2; 
        res = 2*v[d] - 2;
      	if(v[d]==1){res += 1;}
    }
    else{ll d = (v.size())/2 - 1; //cout << d << endl;
        res = v[d] + v[d+1] -2; //cout << v[d] << "," << v[d+1] << endl;
        if(v[d]==1){res = v[d+1]-1;}
    }
  	
    cout << res << endl;
    return 0;
}
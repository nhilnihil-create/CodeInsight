#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n=0,num=1,s;
    
    cin >> n;
    
    vector<ll> vec(n);
    rep(i,n){
    	cin >> vec[i];
      	if(vec[i] == 0){
        	num = 0;
            cout << num << endl;
          	return 0;
        }
    }
  	rep(i,n){
        if(vec.at(i) <= 1000000000000000000/num){
        	num *= vec[i];
    	}else{
        	num = -1;
          	break;
        }
    }
    cout << num << endl;
    
    return 0;
}
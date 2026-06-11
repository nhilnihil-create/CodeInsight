#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)


int main() {
	int N;
  	cin>>N;
  	int kuku[101];
  	
  	rep(i,101){
     	kuku[i] =0;
    }
  	
  	rep(i,9){
     	rep(j,9){
         	int product=(i+1)*(j+1);
          	kuku[product]++;
        }
    }
  	
  	if(kuku[N]) cout<<"Yes"<<endl;
  	else cout<<"No"<<endl;
  	
  	
  
  
}
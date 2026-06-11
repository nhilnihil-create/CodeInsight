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
	int A,B,C,D;
  	cin>>A>>B>>C>>D;
  	while(1){
     	C-=B;
      	if(C<=0){
			cout<<"Yes"<<endl;
          	return 0;
        }
      	A-=D;
      	if(A<=0){
        	cout<<"No"<<endl;
          	return 0;
        }
    }
  
  
}
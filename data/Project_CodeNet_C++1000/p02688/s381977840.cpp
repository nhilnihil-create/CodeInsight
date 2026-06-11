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
	int N,K;
  	cin>>N>>K;
  	int a[N];
  	rep(i,N) a[i]=0;
  
  	rep(i,K){
     	int d;
      	cin>>d;
      	rep(j,d){
         	int b;
          	cin>>b;
          	a[b-1]++;
        }
    }
  	int count=0;
  	
  	rep(i,N){
     	if(a[i]==0) count++; 
    }
  	
  	cout<<count<<endl;
  
}
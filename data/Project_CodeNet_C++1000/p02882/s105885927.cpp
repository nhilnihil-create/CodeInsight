#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	long double a,b,x;
  	cin>>a>>b>>x;
  
  	cout<<fixed<<setprecision(10);
  	if(x<a*a*b/2){
     	cout<<atan(a*b*b/(2*x))*180.0/M_PI; 
    }else{
     	cout<<atan((2*a*a*b-2*x)/(a*a*a))*180.0/M_PI; 
    }
  	
  	
}
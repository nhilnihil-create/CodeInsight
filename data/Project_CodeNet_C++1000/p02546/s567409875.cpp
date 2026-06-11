#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
#define PI 3.14159265358979323846264338327950L
const int mod=1000000007,MAX=200005,INF=1<<30;

int main() {
	string s;
  	cin>>s;
  	
  	int p = s.size()-1;
  
  	if(s[p]=='s'){
    	cout<<s<<"es"<<endl;
    }
  
  	else{
    	cout<<s<<"s"<<endl;
    }
  
  	


}
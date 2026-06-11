#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const int PI = acos(-1);
int main(){
	string s;cin>>s;
	if(s.length()%2){
				cout<<"No"<<endl;
				return 0;
	}
	rep(i,s.length()){
		if(i%2==0){
			if(s[i]!='h'){
				cout<<"No"<<endl;
				return 0;
			}
		}
		else{
			if(s[i]!='i'){
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
}
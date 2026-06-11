#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (a).size() 
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define ford(i,n) for(int i=n;i>=0;i--) 
#define REP(i,a,n) for(int i=a;i<n;i++)
#define foreach(itr,c) for(__typeof((c).begin(),(c).end())itr=c.begin();itr!=c.end();itr++) 
#define fill(a,b) memset(a,b,sizeof(a))
#define re return
#define INF 1e9
#define LINF 1e18
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi > vpi; 
int dsu[200005]; 
int main(){
	int n,q;
	cin>>n>>q;
	rep(i,n){
		dsu[i]=i;
	}
	rep(i,q){
		int a,b,c;
		cin>>a>>b>>c;
		int num1=b,num2=c;
		while(dsu[num1]!=num1){
			num1=dsu[num1];
		}
		dsu[b]=num1;
		while(dsu[num2]!=num2){
			num2=dsu[num2];
		}
		dsu[c]=num2;
		if(a){
			if(num1==num2){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else{
			dsu[num1]=num2;
		}
	}
	re 0;
}
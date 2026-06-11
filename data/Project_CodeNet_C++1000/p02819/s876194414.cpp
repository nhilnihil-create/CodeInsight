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
#define foreach(c,itr) for(__typeof((c).begin(),(c).end())itr=c.begin();itr!=c.end();itr++) 
#define fill(a,b) memset(a,b,sizeof(a))
#define re return
#define INF 1e9
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi > vpi; 
bool isprime[101000];
void findprime(){
	isprime[0]=isprime[1]=0;
	REP(i,2,101000){
		if(isprime[i]){
			for(int j=2;i*j<=101000;j++){
				isprime[i*j]=0;
			}
		}
	}
	re;
}
int main(){
	rep(i,101000){
		isprime[i]=1;
	}
	findprime();
	int x;
	cin>>x;
	while(!isprime[x]){
		x++;
	}
	cout<<x;
	re 0;
}
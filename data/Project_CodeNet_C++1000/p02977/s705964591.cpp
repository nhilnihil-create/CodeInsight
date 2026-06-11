#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int) x.size()
#define f first
#define s second
#define MAXN 100100
int N;

void edge(int a, int b){
	cout<<a<<' '<<b<<'\n';
	// cout<<a%N<<' '<<b%N<<'\n';
}

int main(){
	cin>>N;
	if (N == 1){cout<<"No";return 0;}
	if (N%2 == 1){
		cout<<"Yes\n";
		edge(1,2);
		edge(2,3);
		edge(3,N+1);
		edge(N+1,N+2);
		edge(N+2,N+3);
		for (int i=4;i<N;i+=2){
			edge(i,i+1);
			edge(i+1,1);
			edge(1,i+N);
			edge(i+N, i+N+1);
		}
		return 0;
	}
	int h = 1;
	while (h*2 <= N)h *= 2;
	if (h == N){
		cout<<"No";
		return 0;
	}
	cout<<"Yes\n";
	edge(h+2,h+1);
	edge(h,h+1);
	edge(h+1,3);
	edge(3,1);
	edge(1,2);
	edge(3,2+N);
	edge(2+N,N+h);
	edge(1+N,2+N);
	edge(3,h+N+2);
	edge(h+N+2, h+N+1);
	edge(h+N+1, N+3);
	for (int i=4;i<h;i+=2){
		int t = (i) ^ (i+1);
		edge(i,i+1);
		edge(i+1,1);
		edge(1,i+N);
		edge(i+N, i+N+1);
	}
	for (int i=h+3;i<N;i+=2){
		int t = (i) ^ (i+1);
		edge(i,i+1);
		edge(i+1,t);
		edge(t,i+N);
		edge(i+N, i+N+1);
	}
}
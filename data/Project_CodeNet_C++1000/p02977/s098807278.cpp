/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	fastio;
	int n;
	
	
	cin>>n;
	if(n<3){
		cout<<"No";
		return 0;
	}
	int tmp=n;
	while(tmp%2==0){
		tmp>>=1;
	} 
	if(tmp==1){
		cout<<"No";
		return 0;
	}
	cout<<"Yes"<<endl;
	int N=n;
	if(n%2==0) N--;
	cout<<1<<" "<<2<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<3<<" "<<n+1<<endl;
	
	cout<<n+1<<" "<<n+2<<endl;
	
	cout<<n+3<<" "<<n+2<<endl;
	for(int number=5;number<=N;number+=2){
		cout<<number<<" "<<1<<endl;
		cout<<number-1<<" "<<1<<endl;
		cout<<number-1+n<<" "<<number<<endl;
		cout<<number-1<<" "<<number+n<<endl;
	}
	if(n%2==0){
		int one,base=n^1;
		for(int i=2;i<n;i++){
			if((i^base)<n&&(i^base)>1){
				one=i;
				break;
			}
		}
		cout<<n<<" "<<one<<endl;
		cout<<(one^base)<<" "<<n+n<<endl;
	}
	return 0;
}

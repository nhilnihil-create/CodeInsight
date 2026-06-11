#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 2000000007
#define LINF 1000000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
//typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
int n,k,ans=-LINF;
int p[5555],c[5555];
signed main(){
	cin>>n>>k;
	rep(i,n)cin>>p[i];
	rep(i,n)cin>>c[i];
	int mem[5555];
	rep(i,n){
		int score=0,score2=0,pos=i,cnt=0,sans=-LINF;
		do{
			//cout<<pos<<endl;
			pos=p[pos]-1;
			score+=c[pos];
			cnt++;
			sans=max(sans,score);
			mem[cnt]=sans;
			//cout<<i<<";";DEB(score)END
		}while(pos!=i);
		if(0<=mem[cnt]){
			if(k%cnt==0)ans=max(ans,sans+score*(k/cnt-1));
			score=score*(k/cnt);
			score+=mem[k%cnt];
			ans=max(ans,score);
			//cout<<score<<endl;
		}
		if(k/cnt>0)ans=max(ans,sans);
		else ans=max(ans,mem[k%cnt]);
		
		
		//rep(i,cnt+1)cout<<mem[i]<<" ";
		//cout<<endl;
		//cout<<i<<";";DEB(score)END
	}
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e6+5;
vector<int> s;
vector<int> s2,s3;
vector<int> g[N];

bool vis[N];
void adde(int u,int v){
	if(u&&v)printf("%d %d\n",u,v);
}
int B[N], bs[N];

inline void gen(int sum){
	for(int i=1;i<=n;i++)if(!vis[i]){
		int sum=i;
		for(int j=20;~j;j--){
			if(1&(sum>>j)){
				if(!bs[j]){bs[j]=sum,B[j]=i;break;}
				else sum^=bs[j];
			}
		}
	}
	// for(int i=0;i<20;i++)cout << B[i] << " " << bs[i] << endl;
	for(int i=0;i<1<<20;i++){
		int cur=0;
		for(int j=0;j<20;j++)if(1&(i>>j))cur^=B[j];
		if(cur==sum){
			for(int j=0;j<20;j++)if(1&(i>>j))
				if(B[j])s2.push_back(B[j]);
			break;
		}
	}
	for(size_t i=0;i<s2.size();i++)vis[s2[i]]=1;
	for(int i=1;i<=n;i++)if(!vis[i])s3.push_back(i);
}

inline void prt(vector<int> s){
	for(size_t i=0;i+1<s.size();i++)adde(s[i],s[i+1]),adde(s[i]+n,s[i+1]+n);
}

int main()
{
	cin >> n;
	int l=0;while(1<<l<n)++l;
	if(1<<l==n){
		puts("No");return 0;
	}
	int Xorsum=0;
	for(int j=1;j<=n;j++){
		Xorsum^=j;
	}
	if(n==6) s.push_back(1),s.push_back(6),vis[1]=vis[6]=1;
	else for(int d=0;1<<d<=Xorsum;++d){
		if(1&(Xorsum>>d))s.push_back(1<<d),vis[1<<d]=1;
	}
	puts("Yes");
	if(Xorsum==0){
		for(int i=1;i<n*2;i++)adde(i,i+1);
		return 0;
	}
	// for(size_t i=0;i<s.size();i++)cout << s[i] << " ";puts("|");
	gen(Xorsum);
	// cout << Xorsum << " ::\n";
	// for(size_t i=0;i<s2.size();i++)cout << s2[i] << " ";puts("|");
	// for(size_t i=0;i<s3.size();i++)cout << s3[i] << " ";puts("|");
	prt(s),prt(s2),prt(s3);
	adde(s2.back(),s[0]);
	adde(s.back(),s2[0]+n);
	adde(s.back(),s3[0]+n);
	adde(s3.back(),s[0]);
	adde(s2.back()+n,s[0]+n);
	return 0;
}
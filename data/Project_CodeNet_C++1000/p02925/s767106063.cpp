#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 1010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N][N],t,ok[N][N],q,cnt;
int c[N];
vector<int> vec[4];
int main(){
	n=read();
	q=n*n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		vec[0].push_back(i);
	}
	while(q){
		if(vec[t&1].empty()){
			cout<<-1<<endl;
			return 0;
		}
		for(int i=0;i<vec[t&1].size();i++){
			int p=vec[t&1][i];
			c[p]++;
			q--;
			if(c[p]==n)continue;
			int s=a[p][c[p]];
			ok[s][p]=1;
			if(ok[p][s]){
				vec[(t+1)&1].push_back(p);
				vec[(t+1)&1].push_back(s);
				ok[s][p]=0;
				ok[p][s]=0;
			}
		}
		vec[t&1].clear();
		t++;
	}
	cout<<t-1<<endl;
	return 0;
}

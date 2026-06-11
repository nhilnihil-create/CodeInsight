#include<bits/stdc++.h>
#define maxn 6
using namespace std;
int h,w,tmmp,ans,k;
int a[maxn][maxn],b[maxn][maxn];
char tmp;
int main(){
	cin>>h>>w>>k;
	for(int i=0;i<h;++i)
		for(int j=0;j<w;++j){
		cin>>tmp;
		if(tmp=='#') a[i][j]=1,b[i][j]=1;
		if(tmp=='.') a[i][j]=0,b[i][j]=0;
		}
	for(int i=0;i<(1<<h);++i){
		for(int j=0;j<(1<<w);++j){
			for(int x=0;x<h;++x)
				for(int y=0;y<w;++y)
				if(((1<<x)&i)||((1<<y)&j)) {b[x][y]=0;}
			tmmp=0;
			for(int x=0;x<h;++x)
				for(int y=0;y<w;++y)
				if(b[x][y]==1) tmmp++;
			if(tmmp==k) {ans++;}
			for(int x=0;x<h;++x)
				for(int y=0;y<w;++y)
				b[x][y]=a[x][y];
		}
	}
	cout<<ans;
	return 0;
}
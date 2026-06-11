#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string> 
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int hang[maxn],lie[maxn];

int main()
{
	int h,w,m;scanf("%d%d%d",&h,&w,&m);
	int mxh=0,mxl=0;map<pair<int,int>,int> mp; 
	vector<int> a,b;
	while(m--){
		int hi,wi;scanf("%d%d",&hi,&wi);
		hang[hi]++;lie[wi]++;
		mxh=max(mxh,hang[hi]);
		mxl=max(mxl,lie[wi]);
		mp[make_pair(hi,wi)]=1;
	}
	for(int i=1;i<=h;i++) if(hang[i]==mxh) a.push_back(i);
	for(int i=1;i<=w;i++) if(lie[i]==mxl) b.push_back(i);
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(mp[make_pair(a[i],b[j])]==0){
				printf("%d",hang[a[i]]+lie[b[j]]);
				exit(0);
			} 
		}
	}
	printf("%d",mxh+mxl-1);
	return 0;	
} 
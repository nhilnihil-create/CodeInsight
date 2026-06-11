#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
/*freopen{"input.txt","r",stdin};
freopen{"output.txt","w",stdout};*/
#define mp make_pair
#define pb push_back
const int INF=1000*1000*1000;
const int maxn=2e5; 
typedef long long ll;
typedef long double ld;
typedef pair<int,int>PII;
//priority_queue <int,vector<int>,greater<int> > q1;  //从小到大 
//priority_queue <int,vector<int>,less<int> >q2;  //从大到小 

//set multiset vector queue priority_queue map multimap pair string structure 

//枚举 思维 贪心 搜索 模拟 预处理 二分 排序 
struct node{
	int x,y;
}a[51]; 
bool cmp(struct node p,struct node q){
	if(p.x!=q.x) return p.x<q.x;
	return p.y<q.y;
}
int main(){
	//ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin>>n;
    if(n==1){
    	cout<<1;
    	return 0;
	}
    map<PII,int>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		m[mp(a[i].x,a[i].y)]=1;
	}
	int ans=INF;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
	    if(i==j) continue;
		int x1=a[j].x-a[i].x;
		int y1=a[j].y-a[i].y;
        int tmp=n;
        for(int i=1;i<=n;i++){
        	tmp-=m[mp(a[i].x-x1,a[i].y-y1)];
		}
		ans=min(ans,tmp);	
	}
}
	cout<<ans;
	return 0;
}


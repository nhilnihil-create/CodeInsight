#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}

LL t[100005];

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	LL s=0;
	cin>>n;
	m=0;
	for(i=0;i<n;i++){
		cin>>t[i];
		m^=t[i];
	}
	for(i=60;i>=0;i--){
		a=(LL)1<<i;
		b=-1;
		if(a&m)continue;
		for(j=0;j<n;j++){
			if((a&t[j])==0)continue;
			if(b==-1)b=t[j],t[j]=0;
			else t[j]^=b;
		}
		if(b==-1)continue;
		if((s&a)==0)s^=b;
	}
	cout<<s+(s^m)<<endl;

}
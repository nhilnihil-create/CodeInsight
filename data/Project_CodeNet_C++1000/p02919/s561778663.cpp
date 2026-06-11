#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
const int maxN=1e5+7;
int N;
int p[maxN];
int pos[maxN];
int leftFirstMaxPos[maxN];
int rightFirstMaxPos[maxN];
ll ans=0;
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>p[i];
		pos[p[i]]=i;
		leftFirstMaxPos[i]=i-1;
		rightFirstMaxPos[i]=i+1;
	}
	for(int i=1;i<=N;i++){
		int Lpos1=leftFirstMaxPos[pos[i]];
		int Lpos2=leftFirstMaxPos[Lpos1];
		int Rpos1=rightFirstMaxPos[pos[i]];
		int Rpos2=rightFirstMaxPos[Rpos1];
		if(Lpos1!=0)ans+=(long long)1*i*(Lpos1-Lpos2)*(Rpos1-pos[i]);
		if(Rpos1!=N+1)ans+=(long long)1*i*(pos[i]-Lpos1)*(Rpos2-Rpos1);
		leftFirstMaxPos[Rpos1]=Lpos1;
		rightFirstMaxPos[Lpos1]=Rpos1;
	}
	cout<<ans<<endl;
	return 0;
}
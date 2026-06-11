#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(void){
	int N,M,A1=0,A2=0;
	char S[3];
	scanf("%d %d",&N,&M);
	vector<bool> P(N+1);
	vector<int> P2(N+1);
	for(int i=0;i<M;i++){
		int p;
		scanf("%d %s",&p,S);
		string s=S;
		if(P[p]) continue;
		if(s=="AC") P[p]=true,A1++,A2+=P2[p];
		else P2[p]++;
	}
	printf("%d %d\n",A1,A2);
	return 0;
}
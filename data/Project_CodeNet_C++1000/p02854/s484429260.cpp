#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long int llint;

int main(){
	int N;
	cin >> N;
	llint S[N+1];
	S[0]=0;
	for(int i=1;i<=N;i++){
		llint a;
		cin >> a;
		S[i]=S[i-1]+a;
	}

	llint minCost=-1;
	for(int i=1;i<=N-1;i++){
		llint lenR=S[i];
		llint lenL=S[N]-S[i];
		llint cost=abs(lenR-lenL);
		if(minCost==-1 || cost<minCost){
			minCost=cost;
		}
	}

	cout << minCost << endl;
	return 0;
}

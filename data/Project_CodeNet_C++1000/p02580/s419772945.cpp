#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000001


int main(){

	int H,W,M;
	cin>>H>>W>>M;
	
	vector<int> X(W+1,0),Y(H+1,0);
	set<pair<int,int>> S;
	
	for(int i=0;i<M;i++){
		int h,w;
		scanf("%d %d",&h,&w);
		X[w]++;
		Y[h]++;
		S.insert(make_pair(h,w));
	}
	
	int mX=0,mY=0;
	for(int i=0;i<=W;i++)mX = max(mX,X[i]);
	for(int i=0;i<=H;i++)mY = max(mY,Y[i]);
	
	int ans = mX+mY-1;
	vector<int> okX,okY;
	for(int i=0;i<=W;i++){
		if(X[i]==mX)okX.push_back(i);
	}
	for(int i=0;i<=H;i++){
		if(Y[i]==mY)okY.push_back(i);
	}
	
	for(int i=0;i<okX.size();i++){
		for(int j=0;j<okY.size();j++){
			if(!S.count(make_pair(okY[j],okX[i]))){
				ans ++;
				goto L;
			}
		}
	}
	L:;
	cout<<ans<<endl;
	
	return 0;
}
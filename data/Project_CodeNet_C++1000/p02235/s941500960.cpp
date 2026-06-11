#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib> 
using namespace std;
static const int N = 1000;

int lcs(string X,string Y){
	int **c=(int **)malloc(sizeof(int *)*1001);
	for(int i=0;i<1001;i++){
		c[i]=(int *)malloc(sizeof(int)*1001);
	}
	int m=X.size();
	int n=Y.size();
	int maxl=0;
	X=' '+X;
	Y=' '+Y;
	c[0][0]=0;
	for(int i=1;i<=m;i++) c[i][0]=0;
	for(int j=1;j<=n;j++) c[0][j]=0;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(X[i]==Y[j]){
				c[i][j]=c[i-1][j-1]+1;
			}else{
				c[i][j]=max(c[i-1][j],c[i][j-1]);
			}
			maxl=max(maxl,c[i][j]);
		}
	}
	for(int i=0;i<1001;i++){
		free(c[i]);
	}
	free(c);
	return maxl;
}

int main(){
	string s1,s2;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin >> s1 >> s2;
		cout << lcs(s1,s2) << endl;
	}
	return 0;
}
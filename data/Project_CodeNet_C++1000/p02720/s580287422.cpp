#include<bits/stdc++.h>
using namespace std;
int K;
void DFS(string ANS,int P,int& NOW){
	if(P==0){
		NOW++;
		if(NOW==K) cout <<ANS <<endl;
		return;
	}
	int X=ANS[ANS.size()-1]-'0';
	for(int i=X-1;i<=X+1;i++){
		if(i<0||9<i) continue;
		DFS(ANS+(char)(i+'0'),P-1,NOW);
	}
}
int main(){
	cin >>K;
	int NOW=0;
	for(int i=1;;i++){
		for(int j=1;j<=9;j++){
			string S;
			S+=j+'0';
			DFS(S,i-1,NOW);
			if(NOW>K) return 0;
		}
	}
}

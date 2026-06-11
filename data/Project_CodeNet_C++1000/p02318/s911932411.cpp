#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string x,y;
int main(){
	while(cin >> x >> y){
		int L[x.size()+1][y.size()+1] = {{0}};
		for(int i=0;i<x.size()+1;i++){
			for(int j=0;j<y.size()+1;j++){
				if(i==0){
					L[i][j] = j;
				}else if(j==0){
					L[i][j] = i;
				}else{
					int alpha = 0;
					if(x[i-1]!=y[j-1]) alpha = 1;
					L[i][j] = min(alpha+L[i-1][j-1],min(1+L[i][j-1],1+L[i-1][j]));
				}
			}
		}
		cout << L[x.size()][y.size()] << endl;
	}
}

#if 0
所要時間は40分程度。これも河村先生の講義で扱ったが，アルゴリズムを忘れていたので勉強しなおしだった。
#endif

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_R=10,MAX_C=10000;

bool osenbei[MAX_R][MAX_C];	//true=1,false=0
bool table[MAX_R][MAX_C];
int R,C;

int solve();

int main(){
	vector<int> res;
	do{
		cin>>R>>C;
		if (R!=0 || C!=0){
			for (int i=0;i<R;i++){
				for (int j=0;j<C;j++){
					int a;
					cin>>a;
					osenbei[i][j]=(a ? true:false);
				}
			}
			res.push_back(solve());
		}
	}while (R!=0 || C!=0);
	for (vector<int>::iterator ite=res.begin();ite!=res.end();ite++){
		cout<<*ite<<endl;
	}
	return 0;
}

int solve(){
	int res=0;
	for (int i=0;i<1<<R;i++){
		for (int j=0;j<R;j++){
			for (int k=0;k<C;k++){
				table[j][k]=osenbei[j][k];	//?????????
			}
		}
		for (int j=0;1<<j<=i;j++){
			if (i&(1<<j)){
				//j??????????£???????
				for (int k=0;k<C;k++){
					table[j][k]=!table[j][k];
				}
			}
		}
		int r=0;	//false????????§?????°
		for (int j=0;j<C;j++){
			int f=0;	//false????????°
			for (int k=0;k<R;k++){
				if (!table[k][j]){
					f++;
				}
			}
			f=max(f,R-f);
			r+=f;
		}
		res=max(res,r);
	}
	return res;
}
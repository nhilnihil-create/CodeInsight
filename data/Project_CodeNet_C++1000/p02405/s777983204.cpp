#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> h,w;
	int temph,tempw;
	do{
		cin>>temph>>tempw;
		h.push_back(temph);
		w.push_back(tempw);
	}while (temph!=0 || tempw!=0);
	for (vector<int>::size_type i=0;i<h.size()-1;i++){
		for (int j=0;j<h[i];j++){
			bool flg;
			if (j%2==0){
				flg=true;
			}
			else{
				flg=false;
			}
			for (int k=0;k<w[i];k++){
				if (flg){
					cout<<"#";
				}
				else{
					cout<<".";
				}
				flg=!flg;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
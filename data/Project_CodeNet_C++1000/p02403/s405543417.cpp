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
	}while(temph!=0||tempw!=0);
	for (vector<int>::size_type i=0;i<h.size()-1;i++){
		for (int j=0;j<h[i];j++){
			for (int k=0;k<w[i];k++){
				cout<<"#";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
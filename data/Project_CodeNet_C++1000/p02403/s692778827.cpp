#include <iostream>
#include <vector>
using namespace std;
int main(void){
	vector <int> a,b;
	int x,y;
	do{
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}while(x || y);
	
	for(int t=0;t< a.size()-1;t++){
		for (int i=0;i<a.at(t);i++){
			for (int j=0;j<b.at(t);j++){
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
}
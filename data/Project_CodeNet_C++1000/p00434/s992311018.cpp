#include<iostream>
#include<set>
using namespace std;
int main(){
	int x;
	set<int> box;
	for(int i=1;i<=30;i++)
	box.insert(i);
	for(int i=0;i<28;i++){
		cin>>x;
		box.erase(x);
	}
	set<int>::iterator ite=box.begin();
	cout<<*ite<<endl;
	ite++;
	cout<<*ite<<endl;
	return 0;
}
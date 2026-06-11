// ALDS 1_9_A
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void print_btree(vector<int> btree){
	for(int i=1;i<btree.size();i++){
		cout<<"node "<<i<<": key = "<<btree[i]<<", ";

		if(i != 1)
			cout<<"parent key = "<<btree[i/2]<<", ";
		
		if(2*i < btree.size())
			cout<<"left key = "<<btree[i*2]<<", ";

		if(2*i+1 < btree.size())
			cout<<"right key = "<<btree[2*i+1]<<", ";

		cout<<endl;
	}
}

int main(){
	int H;
	vector<int> btree;

	cin>>H;
	btree.resize(H+1);

	for(int i=1;i<=H;i++)
		cin>>btree[i];

	print_btree(btree);

	return 0;
}
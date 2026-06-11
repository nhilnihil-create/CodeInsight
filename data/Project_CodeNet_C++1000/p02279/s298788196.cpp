#include<iostream>
#include<sstream>
using namespace std;

struct tree{
	int* children;
	int degree;
	int parent;
};

int main(){

	int num;
	cin >> num;
	
	tree* array = new tree[num];
	
	for(int i = 0; i < num; i++){
		int index;
		int degree;
		int childID;
		
		cin >> index;
		cin >> degree;
		array[index].children = new int[degree];
		array[index].degree = degree;
		array[index].parent = -1;
		for(int j = 0; j < degree; j ++){
			cin >> childID;
			array[index].children[j] = childID; 	
		}

	}
	for(int i = 0; i < num; i++){
		for(int j = 0; j < array[i].degree; j++){
			array[array[i].children[j]].parent = i;
		}
	}
	for(int i = 0; i < num; i++){
		//parent
		cout << "node " << i << ": parent = " << array[i].parent << ", ";
		//depth
		int counter = 0;
		int index = i;
		while(array[index].parent != -1){
			counter ++;
			index = array[index].parent;
		}
		cout << "depth = " << counter << ", ";

		//type
		if(array[i].parent == -1)cout << "root";
		else if(array[i].degree == 0)cout << "leaf";
		else cout << "internal node";
		cout << ", ";

		//children
		cout << "[";
		for(int j = 0; j < array[i].degree; j++){
			cout << array[i].children[j]; 
			if(j + 1 != array[i].degree){
				cout << ", ";
			}
		}
		cout << "]";
		cout << endl;
		delete [] array[i].children;
	}
	delete [] array;

	return 0;
}
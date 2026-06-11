#include<iostream>
using namespace std;


int array[100001];

void Partition(const int begin, const int end){
	int mid = array[end];
	int i = begin;
	for(int j = begin; j < end; j++){
		if(array[j] <= mid){
			int buf = array[i];
			array[i] = array[j];
			array[j] = buf;
			i ++;
		}
	}
	{
		int buf = array[i];
		array[i] = array[end];
		array[end] = buf;
	}
	for(int j = 0; j <= end; j++){
		     if(j == i)cout << "[" << array[j] << "] ";  	
		else if(j == end) cout << array[j] << endl;
		else cout << array[j] << " "; 
	}
}

int main(){
	int end;
	cin >> end;
	for(int i = 0; i < end; i++){
		int num;
		cin >> num;
		array[i] = num;
	}
	
	Partition(0, end - 1);
	return 0;
}
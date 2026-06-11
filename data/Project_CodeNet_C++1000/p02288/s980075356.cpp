#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int parent(int i){
	return i/2;
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i +1;
}

int heapsize(vector <int> &x){
	return x.size()-1;
}

int maxheapify(vector <int> &X, int i){
	int l, r;
	l = left(i);
	r = right(i);

	if (r < X.size() && X[l] < X[r] && X[r] > X[i]){
		swap(X[r], X[i]);
		maxheapify(X, r);
	}
	else if (l < X.size() && X[l] > X[i]){
		swap(X[l], X[i]);
		maxheapify(X, l);
	}
	return 0;
}

int buildmaxheap(vector <int> &X){
	int hsize = heapsize(X);
	for (int i= hsize/2; i>0; i--){
		maxheapify(X, i);
	}
	return 0;
}

int main(void){

	int n;
	cin >> n;

	vector <int> X(n+1);

	for (int i=1; i<n+1; i++){
		cin>>X[i];
	}

	buildmaxheap(X);

	stringstream buf;
	for (int i=1; i<n+1; i++){
		buf<<" "<<X[i];
	}
	cout<<buf.str()<<endl;
	buf.str("");
	return 0;
} 
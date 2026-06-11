#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

struct P {
	int id;
	char name;
};

P newP(int id, char name){
	P *v = new P;
	v->id = id; v->name = name;
	return *v;
}

void swap(P& a, P& b){
	P h = newP(a.id, a.name);
	a = b;
	b = h;
}

bool check(vector<P>& A, vector<P> a){
	int *ar1, *ar2;
	int n = A.size();
	ar1 = new int[n]; ar2 = new int[n];
	memset(ar1, 0, n*sizeof(int));
	memset(ar2, 0, n*sizeof(int));
	for(int i=0;i<n;i++){
		if(ar1[i] == 0){
			int rank = 1;
			ar1[i] = rank;
			for(int j=i+1;j<n;j++){
				if(A[i].id == A[j].id){
					rank++;
					ar1[j] = rank;
				}
			}
		}
		if(ar2[i] == 0){
			int rank = 1;
			ar2[i] = rank;
			for(int j=i+1;j<n;j++){
				if(a[i].id == a[j].id){
					rank++;
					ar2[j] = rank;
				}
			}
		}
	}
	bool ans = true;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(A[i].name == a[j].name && A[i].id == a[j].id){
				if(ar1[i] != ar2[j]) ans = false;
			}
		}
	}
	return ans;
}

void BubbleSort(vector<P>& A){
	for(int i = 0;i<A.size();i++){
		for(int j = A.size()-1; j>i; j--){
			if(A[j].id < A[j-1].id){
				swap(A[j], A[j-1]);
			}
		}
	}
}
int SelectionSort(vector<P>& A){
	for(int i = 0; i< A.size(); i++){
		int mini = i;
		for(int j = i; j < A.size(); j++){
			if(A[j].id < A[mini].id){
				mini = j;
			}
		}
		if(i != mini){
			swap(A[i], A[mini]);
		}
	}
}

int main(){
	int n;
	string h;
	vector<P> v,a,b;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> h;
		v.push_back(newP( h[1]-'0', h[0]));
		a.push_back(newP(h[1]-'0', h[0]));
		b.push_back(newP(h[1]-'0', h[0]));
	}
	SelectionSort(a);
	BubbleSort(b); 
	cout << b[0].name << b[0].id;
	for(int i=1;i<n;i++){
		cout << " " << b[i].name << b[i].id;
	}
	cout << endl;
	if(check(v,b)){
		cout << "Stable"<<endl;
	} else {
		cout <<"Not stable"<<endl;
	}
	cout << a[0].name << a[0].id;
	for(int i=1;i<n;i++){
		cout << " " << a[i].name << a[i].id;
	}
	cout << endl;
	if(check(v,a)){
		cout << "Stable"<<endl;
	} else {
		cout <<"Not stable"<<endl;
	}
	return 0;
}
/**************
*	Shell Sort
*************/

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>	//??£?¨?
using namespace std;

void insertionSort(vector<int>* A, int g, int* cnt  ){

	for(unsigned int i=g ; i<(A->size()); i++){
		int v = (*A)[i];
		int j = i-g;
		while(j>=0 && (*A)[j]>v){
			(*A)[j+g] = (*A)[j];
			j = j-g;
			(*cnt)++;
		}
		(*A)[j+g] =v;
	}
	return ;
}
//---------------------------------------------------------
void shellSort(vector<int>* A, vector<int>* G, int* cnt){
//	*cnt =0;
//	int m = A->size();
//	vector<int> G(1,m);
	for(unsigned int i=0; i<(G->size()); i++){
		insertionSort(A, (*G)[i], cnt);
	}

	return;
}
//--<<???????????¢??°>>-------------------------------------------------------
int main(){

	//??\???
	int n;
	cin >> n;
	vector<int> A;
	A.resize(n);
	for(unsigned int i=0; i< A.size(); i++){
		cin >> A[i];
	}

	//??????
// 	vector<int> G(1,1);
	vector<int> G;
// 	for(int i= n; i!=0; --i){
// 	    G.push_back(i) ;
// 	}
vector<int> Temp;
int sum=0;
for(int i=0; i <n ; ++i){
    sum += pow(3,i);
    Temp.push_back(sum);
}
//   for(int i=0; i<Temp.size();i++){cout <<Temp[i] << endl;}

for(int j=0; Temp[j]<=n; j++){
    G.push_back(Temp[j]);
}
//  for(int i=0; i<G.size();i++){cout <<G[i] << endl;}

 reverse(G.begin(), G.end());

	int cnt = 0;
	shellSort(&A, &G, &cnt);

	//??????
	cout << G.size() << endl;
	for(unsigned int i=0; i<(G.size()); i++){
		cout << G[i];
		if(i!=(G.size()-1)){
			 cout <<" " ;
		}
	}
	cout << endl;
	cout << cnt << endl;
	for(int i=0; i< n; i++){
		cout << A[i]<< endl;
	}

	return 0;
}
//-----------------------------------------------
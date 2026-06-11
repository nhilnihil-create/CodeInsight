/**************
*	Shell Sort
*************/

#include <iostream>
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

if(88573 < n){
    G.push_back(88573);
}
if(29524 < n){
    G.push_back(29524);
}
if(9841 < n){
    G.push_back(9841);
}
if(3280 < n){
    G.push_back(3280);
}
if(1093 < n){
    G.push_back(1093);
}
if(364 < n){
    G.push_back(364);
}
if(121 < n){
    G.push_back(121);
}
if(40 <n ){
    G.push_back(40);
}
if(13< n){
G.push_back(13);
}
if(4<n){
    G.push_back(4);
}
if(1<=n){
    G.push_back(1);
}

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
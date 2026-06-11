#include <iostream>
#include <list> //???????????????????????????
#include <vector>//????????¢??????????????????
#include <climits>
using namespace std;


bool solve(int i, int m , vector <int> &A){
	if (m == 0){
		return true;
	}
	
	int n= A.size();
	
	if (i >= n){
		return false;
	}
	
	bool res = solve(i + 1, m, A) || solve(i + 1, m - A[i], A);
	return res;

}

int main(void){
	std::cin.tie(0); 
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i=0 ; i < n; i++){
		cin >> A[i];
	}
	int q;
	cin >> q;
	vector <int> mi(q);
	for(int i=0 ; i < q; i++){
		cin >> mi[i];
	}
	for(int j =0 ; j < q ; j++){
		
		if(solve(0,mi[j],A)){
			cout << "yes" << endl;
		}else cout << "no" << endl;
	}
		
	

}
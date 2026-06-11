#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int A, B;
	cin >> A >> B;
	for(int i = 13; i <= 1000; i++){
		int a = i * 0.08;
		int b = i * 0.1;
		if(a == A && b == B){
		   cout << i << endl;
	       return 0;
		}
 	}
	cout << -1 << endl;
    return 0;	

}













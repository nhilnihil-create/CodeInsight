#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	int M = 0;
	rep(i,N){
		int tmp; cin >> tmp;
		if(M<tmp) M = tmp - 1;
	    else if(M>tmp) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;	
}













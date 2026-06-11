#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int counts = 0;
	rep(i,n+1){
		if(to_string(i).size()%2 ==1) counts++;
	}
	cout << counts -1  << endl;
}
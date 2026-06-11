#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	int a,b;
	cin >> a >> b;
	int kuti = 1;
	int counts = 0;
	while(kuti < b){
		kuti += a -1;
		counts++;
	}
	cout << counts << endl;
}
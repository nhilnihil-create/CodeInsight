#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int N;
vector<int> v;
int main (){
	cin >> N;
	for(int i=0;i<N;i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int ans=0;
	int cnt=0;
	for(int i=0;i<N-1;i++){
		if(v[i] >= v[i+1]) {
			cnt++;
			ans = max(ans,cnt);
		} else cnt = 0;
	}
  cout << ans << endl;
	return 0;
}
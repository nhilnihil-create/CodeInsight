#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K;
  	cin >> N >> K;
  	vector<int> f(N);
  	for(int i=0;i<N;i++) cin >> f.at(i);
  	sort(f.begin(),f.end());
  	int res=0;
  	for(int i=0;i<K;i++) {
    	res += f.at(i);
    }
   cout << res << endl;
}
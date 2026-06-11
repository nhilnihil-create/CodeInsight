#include <bits/stdc++.h>
using namespace std;

long long sumvec(vector<long long> vec){
  long long ans;
  for(int i=0;i<vec.size();i++){
    ans += vec.at(i);
  }
  return ans;
}

int main() {
	int N,K;
	cin >> N >> K;

  	vector<long long> H(N);
  	for(int i=0;i<N;i++){
      cin >> H.at(i);
    }
  	sort(H.begin(),H.end());
  
  	if(K > N){
      cout << 0 << endl;
      return 0;
    }
  	for(int i=0;i<K;i++){
      H.pop_back();
    }
  
	
  	long long attack = sumvec(H);

    cout << attack << endl;
}

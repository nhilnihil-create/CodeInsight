#include <bits/stdc++.h>
using namespace std;

int sumvec(vector<int> vec){
  int ans;
  for(int i=0;i<vec.size();i++){
    ans += vec.at(i);
  }
  return ans;
}

int main() {
	int H,N;
	cin >> H >> N;

  	vector<int> A(N);
  	for(int i=0;i<N;i++){
      cin >> A.at(i);
    }
  
  	int attack = sumvec(A);
  	if(H <= attack) cout << "Yes" << endl;
    else cout << "No" << endl;
}

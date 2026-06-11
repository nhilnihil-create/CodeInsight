#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  string S,T,ans;
  vector<string>s(N);
  vector<string>t(N);  
  
  cin >> S >> T;
  
  //cout << S + T<<endl;
  
  for(int i = 0 ; i < N ; i++){
		s.at(i)=S.at(i);
    	t.at(i)=T.at(i);
  }
  for(int i = 0 ; i < N ; i++){
 	ans += s.at(i) + t.at(i) ;
  }
  
  cout << ans << endl;
	
}

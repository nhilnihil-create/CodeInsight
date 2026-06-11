#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  int sum = 0;
  cin >> s >> t;
  for(int i=0; i < s.size(); i++){
  	if(s.at(i) != t.at(i)){
    	sum += 1;
    }
  }
  cout << sum << endl;
}
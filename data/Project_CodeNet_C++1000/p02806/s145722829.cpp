#include <bits/stdc++.h>

using namespace std;

// Author: Mubashir Ahmad
// Github : @hakerbaya

int main(){
	int n; cin >> n;
  	vector<pair<string,int>> vc;
  	for(int i=0;i<n;i++){
    	string s; cin >> s;
      	int tim; cin >> tim;
      	vc.push_back(make_pair(s,tim));
      }
  	string s; cin >> s;
  	int j;
  	int total = 0;
  	for(int i=0;i<n;i++){
      if(vc[i].first == s){
      	j = i;
      }
    }
  for(int i=j+1;i<n;i++){
      total+=vc[i].second;
    }
  
  if(vc.size() == 1){
  	cout << "0";
  } else{
  	cout << total;
  }
  
  
}
#include <bits/stdc++.h>
using namespace std;
int kind[5] = {' ','A','C','G','T'};

vector<int>hash[2500000];

int convertion(string s){
  int d = 1;
  int sum = 0;
  for(int i = s.size() - 1;i >= 0;i--){
    for(int j = 1;j < 5;j++){
      if(kind[j] == s[i]){sum += d * j;break;}
    }
    d *= 5;
  }
  return sum;
}

int main(){
  string q,s;
  int n;
  cin >> n;
  while(n--){
    cin >> q >> s;
    if(q == "insert"){
      int sum = convertion(s);
      hash[sum / 100].push_back(sum);
    }
    if(q == "find"){
      int sum = convertion(s);
      bool flag = false;
      for(int i = 0;i < hash[sum / 100].size();i++){
	if(hash[sum / 100][i] == sum){cout << "yes" << endl;flag = true;break;}
      }
      if(!flag)cout << "no" << endl;
    }
  }
  return 0;
}
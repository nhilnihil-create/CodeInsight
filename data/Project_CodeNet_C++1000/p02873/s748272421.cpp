#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int N = S.size()+1;
  vector<int> num(N,0);
  int left =0;
  int right=0;
  for(int i = 1; i < N; i++){
    if(S.at(i-1) == '<'){
      left++;
      num.at(i) = left;
    }
    else{
      left = 0 ;
      num.at(i) = left;
    }
  }
  for (int i = 1; i < N; i++){
    if(S.at(N-i-1) == '>'){
      right++;
      num.at(N-i-1)=max(num.at(N-i-1),right);
    }
    else{
      right = 0;
      num.at(N-i-1)=max(num.at(N-i-1),right);
    }
  }
  int64_t sum = 0;
  for(int j = 0; j < N; j++){
    sum+=num.at(j);
  }
  cout << sum << endl;
}


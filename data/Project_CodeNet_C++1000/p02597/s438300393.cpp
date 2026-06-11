#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<char> storn(N);
  for(int i=0;i<N;i++){
    cin >> storn.at(i);
  }
  int count =0;
  for(int i=0;i<N;i++){
    if(storn.at(i)=='R'){
      count++;
    }
  }
  int count2 =0;
  for(int i=0;i<count;i++){
    if(storn.at(i)=='R'){
      count2++;
    }
  }
  cout << count-count2 <<endl;
}
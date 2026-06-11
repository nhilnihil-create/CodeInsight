#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  
  vector<int> a(N+1);
  for(int i = 1; i <= N; i++){
    cin >> a.at(i);
  }
  
  int  num = 0;
  for(int i = 1; i <= N; i += 2){
    if( ((a.at(i) % 2) == 1) ){
      num++;
    }//if
  }//for
  
  cout << num << endl;
  
}
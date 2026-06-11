#include <bits/stdc++.h>
using namespace std;
#define MAX pow(10,18)
typedef long long ll;

int main(){
  
  int N,A=0,t_num,b_num;
  cin >> N;
  for(int i=0;i<N-1;i++){
      cin >> t_num;
      if(i==0) A+=t_num;
      else A+=min(t_num,b_num);
      b_num = t_num;
  }
  A+=t_num;
  
  cout << A << endl;
}
#include <iostream>
#include <vector>
using namespace std;
int main(){
  unsigned long long N,cur;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin >> A.at(i);
  cur=1000;
  for(int i=1;i<N;i++){
    if(A.at(i)>A.at(i-1)){
    	cur=cur+(cur/A.at(i-1))*(A.at(i)-A.at(i-1));
    }
  }
  cout << cur << endl;
}
#include<iostream>
#include<vector>
using namespace std;
int main(){
  int orig[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  vector<int> a(orig,orig+32);
  int input;
  
  cin>>input;
  cout<<a.at(input-1)<<endl;
  
  return 0;
}
#include<iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  int a=(N-1)/1000+1;
  int ans =1000*a-N;
  cout<< ans << endl;
}
 

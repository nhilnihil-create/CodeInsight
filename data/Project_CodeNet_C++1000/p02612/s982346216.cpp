#include<iostream>
using namespace std;

int main() {
  int N;
  cin>>N;
  cout<<((N-1)/1000+1)*1000-N<<endl;
  return 0;
}

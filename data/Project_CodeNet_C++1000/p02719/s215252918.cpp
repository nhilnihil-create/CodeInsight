#include<iostream>
using namespace std;
int main(){

  long long int N;
  long long int K;
  cin>>N>>K;
  long long int ans1=N%K;
  long long int ans2=(N%K-K)*-1;
  long long int ans= ans1<=ans2?ans1:ans2;
  cout<<ans;
  return 0;
}
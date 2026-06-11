#include<iostream>
#define ll long long int

using namespace std;

int main(){
  ll N,sum=0;
  cin >> N;
  for(int i = 1;i <= N;i++){
    if(i % 3 == 0 || i % 5 == 0){
      continue;
    }else{
      sum += i;
    }
  }
  cout << sum << endl;
  return 0;
}

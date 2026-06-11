#include<iostream>
using namespace std;

int main(){
  unsigned long long X;
  cin >> X;
  unsigned long long sum = 100;
  int count=0;
  while(sum<X){
    sum+=sum/100;
    count++;
  }
  cout << count << endl;
}
  

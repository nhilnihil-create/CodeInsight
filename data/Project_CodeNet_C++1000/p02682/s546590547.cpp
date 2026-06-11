#include<iostream>
using namespace std;

int main(){
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  int sum = A+B+C;
  int count=0;
  while(A>0 && K>0){
    A--;
    K--;
    count++;
  }
  while(B>0 && K>0){
    B--;
    K--;
  }
  while(K>0){
    K--;
    count--;
  }
  
  cout << count << endl;
}
    
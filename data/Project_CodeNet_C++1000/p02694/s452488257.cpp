#include<bits/stdc++.h>
using namespace std;

int main(){
  long long X,count=0,cost=100;
  cin >> X;
  while(cost<X){
    count++;
    cost+=cost/100;
  }
  cout << count << endl;
}
  
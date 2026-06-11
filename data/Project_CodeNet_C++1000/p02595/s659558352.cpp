#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, d, sum = 0;
  cin >> n >> d;
  for(int i=0; i < n; i++){
  	double p, q, ans;
    cin >> p >> q;
    ans = pow(p*p+q*q,0.5);
    if(ans <= d){
    	sum += 1;
    }
  }
  cout <<sum <<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,n,h1,n1,k;
  cin >> h >> n >> h1 >> n1 >>k;
  int sum=0 ,sum2=0;
  sum=h*60+n;
  sum2=h1*60+n1;
  int g=sum2-sum;
  cout << g-k << endl;
}

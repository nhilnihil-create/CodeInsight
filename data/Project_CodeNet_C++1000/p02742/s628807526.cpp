#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b;
  cin>>a>>b;
  unsigned long long int c=(a*b+1)/2;
  cout<<(a==1||b==1? 1:c)<<endl;
}
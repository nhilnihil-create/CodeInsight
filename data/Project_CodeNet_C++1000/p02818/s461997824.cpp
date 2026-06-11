#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
  using ll=long long;
  ll A,B,K;
  cin>>A>>B>>K;
  if(A>=K)
    cout<<A-K<<" "<<B<<endl;
  else if(B-K+A<0)
    cout<<"0"<<" "<<"0"<<endl;
  else
    cout<<"0"<<" "<<B-K+A<<endl;
}
    
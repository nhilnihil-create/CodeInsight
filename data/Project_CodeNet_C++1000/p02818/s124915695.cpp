#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  	long long A; long long B; long long  K;
  cin>>A>>B>>K;
  if(A>=K)
    cout<<A-K<<" "<<B<<endl;
  else if(A+B>=K)
    cout<<0<<" "<<A+B-K<<endl;
  else cout<<0<<" "<<0<<endl;
}
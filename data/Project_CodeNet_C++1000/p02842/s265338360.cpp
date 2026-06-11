#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a=n*100/108;
  if((int)(a*1.08)==n)
    cout<<a<<endl;
  else if((int)((a+1)*1.08)==n)
    cout<<(a+1)<<endl;
  else
    cout<<":("<<endl;
}

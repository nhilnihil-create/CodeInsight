#include <bits/stdc++.h>
using namespace std;

int main() {
int a,b,c;
  c=0;
  cin>>a>>b;
  for(int64_t i=0;i<=a;i++){if(b==2*i+4*(a-i)){cout<<"Yes"<<endl;
                                             c=1;
                                            break;}}
  if(c==0){cout<<"No"<<endl;}
}

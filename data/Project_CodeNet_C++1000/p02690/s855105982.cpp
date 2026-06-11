#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x;
  cin>>x;
	for(long long a=1;a<=100LL;++a) {
      for(long long b=-a;b<a;++b) {
    	if(a*a*a*a*a-b*b*b*b*b==x){
            cout<<a<<" "<<b<<endl;
            return 0;
          }
      }
  }
  for(long long a=101;a<=200LL;++a){
  	for(long long b=0;b<a;++b){
      if(a*a*a*a*a-b*b*b*b*b==x){
         cout<<a<<" "<<b<<endl;
         return 0;
        }
      }
  }
  cout << endl;
}
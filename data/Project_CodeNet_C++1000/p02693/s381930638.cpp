#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll K,A,B;
  cin>>K>>A>>B;
  if(A%K==0) {
cout<<"OK"<<endl;
    return 0;
  }
  
  else if(A/K<B/K) {
cout<<"OK"<<endl;
  }
  else {
cout<<"NG"<<endl;
  }
}

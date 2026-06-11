#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  reverse(all(S));
  if(S[0]=='3') {
cout<<"bon"<<endl;
  }
  else if(S[0]=='0'||S[0]=='1'||S[0]=='6'||S[0]=='8') {
cout<<"pon"<<endl;
  }
  else {
cout<<"hon"<<endl;
  }
}
  
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  string a;
  cin>>a;
  ll b=a.size();
  char c=a.at(b-1);
  if(c=='3'){
    cout<<"bon"<<endl;
  }
  else if(c=='0'||c=='1'||c=='6'||c=='8'){
    cout<<"pon"<<endl;
  }
  else{
    cout<<"hon"<<endl;
  }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  string n;
  cin>>k>>n;
  if(n.size()<=k)
    cout<<n<<endl;
  else{
    for(int i=0;i<k;i++)
      cout<<n[i];
    cout<<"..."<<endl;
  }
}
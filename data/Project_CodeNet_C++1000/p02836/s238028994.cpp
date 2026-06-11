#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin>>str;
  int N =str.size();
  int count=0;
  for(int i=0;i<N/2;i++){
      if(str.at(i)!=str.at(N-1-i)){
        count++;
      }
  }
  cout<<count<<endl;
}

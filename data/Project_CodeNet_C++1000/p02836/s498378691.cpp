#include <bits/stdc++.h>
using namespace std;

int main(){
 string s;
  cin>>s;
  int N=(int)s.size();
  int sum=0;
  for(int i=0;i<N/2;i++){
    if(s.at(i)!=s.at(N-1-i)){
      sum++;
    }
  }
  cout<<sum<<endl;
}
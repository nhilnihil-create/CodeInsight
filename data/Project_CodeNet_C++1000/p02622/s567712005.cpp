#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s >> t;
  int num=s.size();
  int count=0;
  for(int i=0;i<num;i++){
    if(s.at(i)!=t.at(i)){
      count++;
    }
  }
  cout << count << endl;
}
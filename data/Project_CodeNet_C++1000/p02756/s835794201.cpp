#include<bits/stdc++.h>
using namespace std;

int main(){
  int Q,b,rev=0;
  string S;
  char c;
  cin >> S >> Q;
  vector<char>right;
  vector<char>left;
  for(int i=0;i<Q;i++){
    cin >> b;
    if(b==1){
      rev++;
    }else{
      cin >> b >> c;
      if(rev%2!=b-1)
        right.push_back(c);
      else
        left.push_back(c);
    }
  }
  if(rev%2==1){
    reverse(S.begin(),S.end());
    for(int i=right.size()-1;i>=0;i--)
      cout << right.at(i);
    cout << S;
    for(int i=0;i<left.size();i++)
      cout << left.at(i);
    cout << endl;
  }else{
    for(int i=left.size()-1;i>=0;i--)
      cout << left.at(i);
    cout << S;
    for(int i=0;i<right.size();i++)
      cout << right.at(i);
    cout << endl;
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin >> n >> s;
  int k=s.size();
  for(int i=0;i<k;i++){
    int num=s[i]-'A';
    num=(num+n)%26;
    s[i]=num+'A';
    cout << s[i];
  }
  cout << endl;
}

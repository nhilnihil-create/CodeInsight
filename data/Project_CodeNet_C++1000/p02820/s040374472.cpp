#include<bits/stdc++.h>
using namespace std;

int main(){
  string t;
  int r,s,p,k,n;
  cin >> n >> k >> r >> s >> p >> t;
  int ans=0;
  queue<char>ng;
  for(int i=0;i<k;i++)
    ng.push('/');
  for(int i=0;i<n;i++){
    if(ng.front()==t.at(i)){
      ng.push('/');
    }else{
      switch(t.at(i)){
        case 's':
          ans+=r;
          break;
        case 'r':
          ans+=p;
          break;
        case 'p':
          ans+=s;
          break;
      }
      ng.push(t.at(i));
    }
    ng.pop();
  }
  cout << ans << endl;
  return 0;
}
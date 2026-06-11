#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int q;
  string s;
  cin >> s >> q;
  int flag = 1;
  string front="", back ="";
  rep(i,q){
    int num;
    cin >> num;
    if(num == 1){
      flag *= -1;
    }else{
      cin >> num;
      string c;
      cin >> c;
      if((num==1 && flag==1) || (num==2 && flag==-1)){
        front += c;
      }else{
        back += c;
      }
    }
  }
  reverse(front.begin(), front.end());
  s = front + s + back;
  if(flag==1)cout << s << endl;
  else{
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
  return 0;
}
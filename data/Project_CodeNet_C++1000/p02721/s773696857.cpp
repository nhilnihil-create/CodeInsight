#include <iostream>
using namespace std;

int main(){
  int n, k, c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  int l[k]={0}, r[k]={0};
  int x=0;
  for(int i=0;i<k;i++){
    while(s[x]=='x'){
      x+=1;
    }
    l[i]=x;
    //cout << x << endl;
    x += c+1;
  }
  int y=n-1;
  for(int i=k-1;i>=0;i--){
    while(s[y]=='x'){
      y-=1;
    }
    //cout << y << endl;
    r[i]=y;
    y -= c+1;
  }
  for(int i=0;i<k;i++){
    if(r[i]==l[i]){
      cout << r[i]+1 << endl;
    }
  }
}
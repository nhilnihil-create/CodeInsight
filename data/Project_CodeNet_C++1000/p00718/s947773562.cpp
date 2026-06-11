#include <iostream>
#include <string>
using namespace std;

int henkan(string);
string henkan(int);
bool suuzi(char);
int mcxi(char);
main(){
  int n;
  while(cin >> n){
    for(int i=0;i<n;i++){
      string in1, in2;
      cin >> in1 >> in2;
      int a, b, c;
      a = henkan(in1);
      b = henkan(in2);
      c=a+b;
      string ans;
      ans = henkan(c);
      cout << ans << endl;
    }
  }
  return 0;
}

int henkan(string in){
  int sum=0;
  int size=in.size();
  for(int i=0;i<size;i++){
    int r;
    if(suuzi(in[i])){
      r=in[i]-'0';
      for(int j=0;j<r;j++){
        sum+=mcxi(in[i+1]);
      }
      i++;
    }
    else{
      sum+=mcxi(in[i]);
    }
  }
  return sum;
}

string henkan(int n){
  string ans="";
  int a, b, c, d;
  char ac, bc, cc, dc;
  a=n/1000;
  ac=(char)a+'0';
  n-=a*1000;
  b=n/100;
  bc=(char)b+'0';
  n-=b*100;
  c=n/10;
  cc=(char)c+'0';
  n-=c*10;
  d=n;
  dc=(char)d+'0';
  if(a>1){
    ans+=ac;
  }
  if(a>0){
    ans+='m';
  }
  if(b>1){
    ans+=bc;
  }
  if(b>0){
    ans+='c';
  }
  if(c>1){
    ans+=cc;
  }
  if(c>0){
    ans+='x';
  }
  if(d>1){
    ans+=dc;
  }
  if(d>0){
    ans+='i';
  }
  return ans;
}

bool suuzi(char c){
  if(c>='0' && c<='9') return true;
  return false;
}

int mcxi(char c){
  if(c=='m') return 1000;
  else if(c=='c') return 100;
  else if(c=='x') return 10;
  else return 1;
}
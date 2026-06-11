#include <iostream>
#include <string>

using namespace std;

int R, S, P;

int tokuten(char t){
  if(t == 'r') return R;
  if(t == 's') return S;
  if(t == 'p') return P;
}

char kachite(char t){
  if(t == 'r') return 'p';
  if(t == 's') return 'r';
  if(t == 'p') return 's';
}

string dasute(int R, int S, int P){
  int a[] = {R, S, P};
  int m;
  string s = {"rsp"};
  char c;
/*
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      if(a[j]>a[j+1]){
        m=a[j];
        c=s[j];
        a[j]=a[j+1];
        s[j]=s[j+1];
        a[j+1]=m;
        s[j+1]=c;
      }
    }
  }
*/
  return s;
}

int main(void){

  int N, K;
  int x = 0;
  string T;
  string te, l;

  cin >> N >> K;
  cin >> R >> S >> P;
  cin >> T;

  l = dasute(R, S, P);

  for(int i=0; i<N; i++){
    if(i<K || kachite(T[i])!=te[i-K]){
      te+=kachite(T[i]);
      x+=tokuten(te[i]);
    }
    else{
      for(int j=0; j<3; j++){
        if(l[j]!=te[i-K] && l[j]!=kachite(T[i+K])){
          te+=l[j];
          break;
        }
      }
    }
  }
  cout << x << endl;

  return 0;
}
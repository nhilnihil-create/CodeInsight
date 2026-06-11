#include <bits/stdc++.h>
using namespace std;
vector<char> S(10);
int N;
void doukei(int n){
  if(n==N-1){
    if(n==0){
      cout << 'a' << endl;
    }else{
      char m='a';
      for(int i=0;i<n;i++){
        m=max(m,S.at(i));
      }
      for(char i='a';i<=m+1;i++){
        S.at(n)=i;
        for(int j=0;j<N;j++){
          cout << S.at(j);
        }
        cout << endl;
      }
    }
  }else if(n==0){
    doukei(1);
  }else{
    char m='a';
    for(int i=0;i<n;i++){
      m=max(m,S.at(i));
    }
    for(char i='a';i<=m+1;i++){
      S.at(n)=i;
      doukei(n+1);
    }
  }
}
int main(){
  
  cin >> N;
  
  for(int i=0;i<N;i++){
    S.at(i)='a';
  }
  doukei(0);
  
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,cyc=0;
  string S;
  cin >> S >> N;
  char f=S.at(0);
  int a=0;
  ulong b=0;
  int64_t ans=0;
  if(N==1){
    bool ok=false;
    for(int i=0;i<S.size()-1;i++){
      if(S.at(i)==S.at(i+1)&&!ok){
        cyc++;
        ok=true;
      }else{
        ok=false;
      }
    }
    cout << cyc << endl;
    return 0;
  }
  while(a<S.size()&&S.at(a)==f){
    a++;
    b++;
  }
  if(a==S.size()){
    cout << S.size()*N/2 << endl;
    return 0;
  }
  a=S.size()-1;
  while(a>=0&&S.at(a)==f){
    a--;
    b++;
  }
  //cout << a << "/" << b << endl;
  if(b%2==1){
    bool ok=false;
    for(int i=0;i<S.size()-1;i++){
      if(S.at(i)==S.at(i+1)&&!ok){
        cyc++;
        ok=true;
      }else{
        ok=false;
      }
    }
    //cout << cyc << endl;
    ans=cyc*N;
  }else{
    int i=0,j=S.size()-1;
    while(i<N&&S.at(i)==f)
      i++;
    while(j>=0&&S.at(j)==f)
      j--;
    bool ok=false;
    for(int k=i;k<j;k++){
      if(S.at(k)==S.at(k+1)&&!ok){
        cyc++;
        ok=true;
      }else{
        ok=false;
      }
    }
    //cout << cyc << '#' << j << '/' << i << endl;
    ans=cyc*N;
    ans+=min(S.size(),S.size()-j+i)/2*(N-1)+i/2+(S.size()-j-1)/2;
  }
  cout << ans << endl;
  return 0;
}
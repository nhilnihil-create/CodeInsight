#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
int N, M;
vb box;

#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define debug2(x,y) cout<<"("<<#x<<","<<#y<<") = ("<<(x)<<","<<(y)<<")\n"

bool checkbox(int i, int a){
  //i番目の箱 余りa
  int buf = 0;
  for(int k=i; k<=N; k+=i){
    if(box[k])buf++;
    //debug(buf);
  }
  //debug2(buf, a);
  if(buf%2 == a){
    return false;
  }else{
    M++;
    //debug(M);
    return true;
  }
}

int main(){
  cin>>N;
  box.resize(N+1, false);
  vi a(N+1);
  for(int i=1; i<=N; i++)cin>>a[i];
  M=0;
  for(int i=N; i>=1; i--){
    box[i] = checkbox(i, a[i]);
    //debug(box[i]);
  }

  cout<<M<<endl;
  if(M==0)return 0;
  for(int i=1; i<=N; i++){
    if(box[i]){
      cout<<i<<" ";
    }
  }
  cout<<endl;
}
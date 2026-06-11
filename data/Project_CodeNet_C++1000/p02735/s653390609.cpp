#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string> A(H+1);
  string S="";
  for(int i=0;i<=W;i++)
    S+='.';
  A[0]=S;
  for(int i=1;i<=H;i++){
    cin>>A[i];
    A[i]='.'+A[i];
  }
  vector<vector<int>> B(H+1,vector<int>(W+1));
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      int a=B[i-1][j],b=B[i][j-1];
      if(A[i][j]=='#' && A[i-1][j]=='.')
        a++;
      if(A[i][j]=='#' && A[i][j-1]=='.')
        b++;
      if(i==1)
        B[i][j]=b;
      else if(j==1)
        B[i][j]=a;
      else
        B[i][j]=min(a,b);
    }
  }
  cout<<B[H][W]<<endl;
}
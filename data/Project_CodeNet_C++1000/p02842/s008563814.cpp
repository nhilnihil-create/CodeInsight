#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  int K=N/1.08;
  if((int)(K*1.08)==N)
    cout<<K<<endl;
  else if((int)((K+1)*1.08)==N)
    cout<<K+1<<endl;
  else
    cout<<":("<<endl;
}
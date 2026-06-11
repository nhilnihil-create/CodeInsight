#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  string T;
  cin>>S>>T;
  vector<vector<int>> A(26);
  for(int i=0;i<S.size();i++)
    A[S[i]-'a'].push_back(i);
  int ans=0,n=-1;
  for(int i=0;i<T.size();i++){
    if(A[T[i]-'a'].size()==0){
      puts("-1");
      return 0;
    }
    int it=upper_bound(A[T[i]-'a'].begin(),A[T[i]-'a'].end(),n)-A[T[i]-'a'].begin();
    if(it==A[T[i]-'a'].size())ans++,n=A[T[i]-'a'][0];
    else n=A[T[i]-'a'][it];
  }
  cout<<ans*S.size()+n+1<<endl;
}
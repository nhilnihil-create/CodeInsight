#include <bits/stdc++.h>
using namespace std;
int main(){
  string S; cin>>S;
  int Q; cin>>Q;
  deque<char>A;
  for(int i=0;i<S.size();i++)A.push_back(S.at(i));
  bool B=false;
  int count=0;
  for(int i=0;i<Q;i++){
    int T; cin>>T;
    if(T==1)B=(B==false? true:false);
    else{
      int F; cin>>F;
      char C; cin>>C;
      if((B==true&&F==1)||(B==false&&F==2))A.push_back(C);
      else A.push_front(C);
      count++;
    }
  }
  if(B==false)for(int i=0;i<count+S.size();i++){cout<<A.front();A.pop_front();}
  else for(int i=count+S.size();i>0;i--){cout<<A.back();A.pop_back();}
  cout<<endl;
}
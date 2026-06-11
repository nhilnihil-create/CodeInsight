#include<iostream>
using namespace std;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)



int main(){
  int N;
  string s;
  set<string>st;
cin>>N;
rep(i,N){
  cin>>s;
  st.insert(s);
}
cout<<st.size()<<endl;
return 0;
}
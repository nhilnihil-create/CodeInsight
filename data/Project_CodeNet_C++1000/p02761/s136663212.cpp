#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
 vector<int> vec(n,-1);
  for(int i=0;i<m;i++){
    int s,c;
    cin>>s>>c;
    s--;
    if(n!=1&&s==0&&c==0){
      cout<<-1<<endl;
      return 0;
    }
    if(vec.at(s)==-1){
      vec.at(s)=c;
    }
    else if(vec.at(s)!=c){
      cout<<-1<<endl;
      return 0;
    }
  }
 for(int i=0;i<n;i++){
   if(n!=1&&i==0&&vec.at(i)==-1){
     vec.at(i)=1;
   }
   else if(vec.at(i)==-1){
     vec.at(i)=0;
   }
   cout<<vec.at(i);
 }
  cout<<endl;
  
  
  
}

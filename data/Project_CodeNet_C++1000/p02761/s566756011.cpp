#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N,M,s,c,Ans=0;
  cin>>N>>M;
  vector<int> vec(3);
  vec.at(0)=-1;
  vec.at(1)=-1;
  vec.at(2)=-1;
  
  rep(i,M){cin>>s>>c;
         if(vec.at(s-1)==-1||vec.at(s-1)==c){vec.at(s-1)=c;}else{Ans=-1;break;}
        }
  if(Ans==-1){cout<<-1<<endl;}
  else if(N==1){if(vec.at(0)==-1){vec.at(0)=0;}cout<<vec.at(0)<<endl;}
  else if(vec.at(0)==0){cout<<-1<<endl;}
  else{if(vec.at(0)==-1){vec.at(0)=1;}
       if(vec.at(1)==-1){vec.at(1)=0;}
       
       if(N==2){cout<<vec.at(0)*10+vec.at(1)<<endl;}
       else {if(vec.at(2)==-1){vec.at(2)=0;}cout<<vec.at(0)*100+vec.at(1)*10+vec.at(2)<<endl;}
      }
}

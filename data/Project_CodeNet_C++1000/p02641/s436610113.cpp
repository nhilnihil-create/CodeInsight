#include <bits/stdc++.h>
using namespace std;

int main() {
  int X,N;
  cin>>X>>N;
  vector<int>vec(N+1);
  for(int i=0;i<N;i++){cin>>vec.at(i);}
  vec.at(N)=130;
for(int u=0;u<N;u++){for(int v=u+1;v<N;v++){if(vec.at(u)==vec.at(v)){
  vec.at(v)=120;
  }}}
     sort(vec.begin(),vec.end());
  int p,q=0;
  for(int j=0;j<N;j++){if(X!=vec.at(j)){p++;}
                else{q=j;
             break; }  }
  if(p==N){cout<<X<<endl;}
  else{
    for(int k=0;k<N;k++){if(q-k-1>=0 && q+k+1<N+1){
  if(vec.at(q-k-1)!=X-k-1){cout<<X-k-1<<endl;
                          break;}
      else if(vec.at(q+k+1)!=X+k+1){cout<<X+k+1<<endl;
                          break;}
      else if(q-k-1==0 && vec.at(q+k+1)!=120){cout<<X-k-2<<endl;
                 break;}
      else if(vec.at(q+k+1)==120){cout<<X+k+2<<endl;
      break;}}
      else if(q==0){cout<<vec.at(0)-1<<endl;
                   break;}

  }}
  }



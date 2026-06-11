#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N,A,x,y;
  cin>>N;
  vector<int> tru(N);
 vector<vector<int>> data(N, vector<int>(N));
  
  rep(i,N){rep(j,N){data.at(i).at(j)=-1;}}
  rep(i,N){cin>>A;
          rep(j,A){cin>>x>>y;
                  data.at(i).at(x-1)=y;}
          }
  
  int Ans=0;
  int tmp=0;
  int flg=1;
 
  for (int bit = 0; bit < (1<<N); ++bit){
    for (int i = 0; i < N; ++i) {
      if (bit & (1<<i)){tru.at(i)=1;tmp++;}
      else{tru.at(i)=0;}
    }

    
    rep(k,N){if(tru.at(k)==1){
      rep(l,N){if(data.at(k).at(l)==1&&tru.at(l)==0){flg=0;}
               if(data.at(k).at(l)==0&&tru.at(l)==1){flg=0;}
              }
    }
    
            }      
            if(flg==1){Ans=max(Ans,tmp);}   
    flg=1;tmp=0;
}
  cout<<Ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,M,SUM=0;
  cin>>N>>M;

  vector<int> A(N);
  rep(i,N){cin >> A.at(i);
          SUM+=A.at(i);}
  
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  int flg=0;
  
rep(i,N){if(A.at(i)*4*M>=SUM){flg++;if(flg>=M){break;}
                         }else{break;}
        }
  if(flg>=M){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  long long Ans=1,B=1000000000000000000;
  cin>>N;
  vector<long long> vec(N);
    rep(i,N){cin>>vec.at(i);
            if(vec.at(i)==0){Ans=0;break;}
            }
  
  rep(i,N){if(Ans==0){break;}
            if(B/Ans>=vec.at(i)){Ans*=vec.at(i);}
            else{Ans=-1;break;}}
  cout<<Ans<<endl;
}

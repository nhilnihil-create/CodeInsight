#include<bits/stdc++.h>
using namespace std;
typedef pair<long,long> P;
int main(){
  long N;cin>>N;
  vector<long>S(1<<N);
  for(long i=0;i<(1<<N);i++)cin>>S[i];
  sort(S.begin(),S.end(),greater<long>());
  vector<P>A;//値と個数
  for(long i=0;i<(1<<N);i++){
    if(i==0||A[A.size()-1].first!=S[i])A.push_back(P(S[i],1));
    else A[A.size()-1].second++;
  }
  long M=A.size();
  vector<long>B(M);//個数
  B[0]=1;
  for(long i=0;i<N;i++){
    vector<long>C(M);long rem=0;
    for(long j=0;j<M-1;j++){
      //枠Aに治るまで, Bを右に移動. 2つ以上いけるはず
      // 1個下にはいくつBが移動できるか
      //   使えるのはB[j]+rem
      //   = A[j+1]-B[j+1]: 空いているかず
      //    溢れるかどうか: B[j]+rem>(A[j+1]-B[j+1])なら溢れる
      //    その時は次に回す
      // 
      if(rem+B[j]>A[j+1].second-B[j+1]){
        rem=rem+B[j]-(A[j+1].second-B[j+1]);
        C[j+1]=A[j+1].second-B[j+1];
      }
      else{
        C[j+1]=B[j]+rem;
        rem=0;
      }
    }
    for(long j=0;j<M;j++)B[j]+=C[j];
    //for(long j=0;j<M;j++)cout<<B[j]<<" ";cout<<endl;
  }
  for(long i=0;i<M;i++)if(A[i].second!=B[i]){cout<<"No";return 0;}
  cout<<"Yes";
}
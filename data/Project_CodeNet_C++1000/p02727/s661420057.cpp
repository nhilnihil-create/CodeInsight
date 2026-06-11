#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){

  long long X,y,a,b,c;
 cin>>X>>y>>a>>b>>c;
  vector<int>R,B,T;


  long long x;

  for(int i=0;i<a;i++){
    cin>>x;
    R.push_back(x); }

    for(int i=0;i<b;i++){
    cin>>x;
     B.push_back(x); }

  for(int i=0;i<c;i++){
    cin>>x;
    T.push_back(x); }

   sort(R.begin(),R.end(),greater<int>());
   sort(B.begin(),B.end(),greater<int>());

 for(int i=0;i<X;i++)
    T.push_back(R[i]);

 for(int i=0;i<y;i++)
  T.push_back(B[i]);

    sort(T.begin(),T.end(),greater<int>());

   long long sum=0;
 for(int i=0;i<X+y;i++){
    sum += T[i];
 }

  cout<<sum<<endl;

return 0;
}
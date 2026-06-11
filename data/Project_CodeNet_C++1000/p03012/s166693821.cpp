#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
 int N;
 cin>>N;
 vector<int>W(N);int sum=0;
 for(int i=0;i<N;i++){
   cin>>W[i];sum+=W[i];
 }
 int left=0;int right=0;int ans=999999;
 for(int i=0;i<N;i++){
   left+=W[i];right=sum-left;
   ans=min(abs(left-right),ans);
 }
 cout<<ans<<endl;
   return 0;
}
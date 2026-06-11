#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N;
cin>>N;
vector<int> h(N);
for(int i=0;i<N;i++){
   cin>>h[i];
}
reverse(h.begin(),h.end());
bool t=true;
for(int i=0;i<N-1;i++){
   if(h[i]+1==h[i+1]){
      h[i+1]-=1;
   }
   else if(h[i]+2<=h[i+1]){
   t=false;
   }
}
if(t){
   cout<<"Yes"<<endl;
}
else{
   cout<<"No"<<endl;
}
return 0;
}
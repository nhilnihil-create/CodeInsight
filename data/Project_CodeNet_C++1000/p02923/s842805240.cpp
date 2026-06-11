#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N;
cin>>N;
vector<int> h(N);
rep(i,N)cin>>h[i];
reverse(h.begin(),h.end());
int a=0;
int x=0;
for(int i=1;i<N;i++){
   if(h[i-1]<=h[i]){
      x++;
   }
   else{
      x=0;
   }
   a=max(a,x);
}
cout<<a<<endl;
return 0;
}
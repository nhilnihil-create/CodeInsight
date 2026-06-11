#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N;
cin>>N;
map<int,int>mp;
vector<int>v(N);
for(int i=0;i<N;i++){
   cin>>v[i];
   
}
   vector<int> a(N);
for(int i=0;i<N;i++){
   a[v[i]-1]=i+1;
}
for(int i=0;i<N;i++){
   cout<<a[i]<<endl;
}

return 0;

}
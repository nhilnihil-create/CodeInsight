#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N;
cin>>N;
vector<int>a(N);
vector<int>b(N-1);
for(int i=0;i<N-1;i++){
cin>>b[i];
}
a[0]=b[0];
a[N-1]=b[N-2];
for(int i=1;i<=N-2;i++){
   a[i]=min(b[i-1],b[i]);
}
int x=0;
for(int i=0;i<N;i++){
   x+=a[i];
}
cout<<x<<endl;
return 0;
}
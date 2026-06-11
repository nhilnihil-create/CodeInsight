#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N;
cin>>N;
vector<int> d(N);
for(int i=0;i<N;i++){
   cin>>d[i];
}
sort(d.begin(),d.end());
int a=d[N/2]-d[N/2-1];
cout<<a<<endl;


return 0;
}

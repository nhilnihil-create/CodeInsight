#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;

int main(){
int N;
cin>>N;
vector<int>v(N);
for(int i=0;i<N;i++){
   cin>>v[i];
}
sort(v.begin(),v.end());
vector<double>a(N);
a[0]=v[0];
for(int i=1;i<N;i++){
   a[i]=(a[i-1]+v[i])/2.0;

}

cout<<a[N-1]<<endl;
return 0;
}
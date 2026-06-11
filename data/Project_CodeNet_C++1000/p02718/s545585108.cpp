#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++) ;
int main() {
long double N,M;
cin>>N>>M;
vector<long double>A(N);
long double count=0;
for(int i=0; i<N; i++){
    cin>>A.at(i);
    count+=A.at(i);
}
count=count/(4*M);
long double answer=0;
for(int i=0; i<N; i++){
    if(count<=A.at(i)){
        answer++;
    }
}
if(M<=answer){
    cout<<"Yes"<<endl;
}
else
cout<<"No"<<endl;
}

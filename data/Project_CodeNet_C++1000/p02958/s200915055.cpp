#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,N) for (int i = 0; i < N; i++) ;                                
int main() {
 int N;
 cin>>N;
 vector<int>P(N);
 for(int i=0; i<N; i++){
     cin>>P.at(i);
 }
 vector<int>A(N);
 A=P;
 sort(P.begin(),P.end());
 int count=0;
for(int i=0; i<N; i++){
    if(P.at(i)==A.at(i)){
    }
    else{
    count++;
    }
}
if(count<3){
    cout<<"YES"<<endl;
}
else
{
    cout<<"NO"<<endl;
}
}

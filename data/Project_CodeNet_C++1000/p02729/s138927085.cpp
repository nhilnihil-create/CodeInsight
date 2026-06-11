#include<iostream>
 using namespace std;
int main(){
int N,M;
cin>>N>>M;
  int ans=N*(N-1)/2+M*(M-1)/2;
cout<<ans;
return 0;
}
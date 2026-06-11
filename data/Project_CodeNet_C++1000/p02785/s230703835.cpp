#include<bits/stdc++.h>
using namespace std;

int main(){
int N;
cin>>N;
int K;
cin>>K;
vector<long long> H(N);
for(int i=0;i<N;i++){
  cin>>H[i];
}
 sort(H.begin(), H.end()); 
 reverse(H.begin(), H.end()); 
 long long a=0;
 for(int i=K;i<N;i++){
   a+=H[i];
 }
 cout<<a<<endl;
 return 0;

}

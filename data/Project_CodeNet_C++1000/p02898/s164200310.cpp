#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  int A[100000];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  
  int sum=0;
   for(int i=0;i<n;i++){
     if(A[i]>=k)sum++;
   }
 cout<<sum<<endl;
}
  
  
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  int n;
  cin>>n;
  int A[n];
  double sum=0;
  rep(i,n){cin>>A[i];
          }
  rep(i,n){ sum+=1.0/A[i];  }
  cout<<fixed<<setprecision(15)<<1/sum<<endl;
  
    
}
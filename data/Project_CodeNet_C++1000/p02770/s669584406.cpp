#include<bits/stdc++.h>
using namespace std;
int main() {
  long long k,q;cin>>k>>q;
  vector<long long>d(k);for(long long i=0;i<k;i++)cin>>d[i];
  for(long long Q=0;Q<q;Q++){
    long long N,X,M;cin>>N>>X>>M;X%=M;
    long long C=0;
    vector<long long>D(k);for(long long i=0;i<k;i++){
      D[i]=d[i]%M;if(D[i]==0)D[i]=M;C+=D[i];
    }
    long long S=X;S+=C*((N-1)/k);for(long long i=0;i<(N-1)%k;i++)S+=D[i];
    cout<<N-(S/M)-1<<endl;
  }
}


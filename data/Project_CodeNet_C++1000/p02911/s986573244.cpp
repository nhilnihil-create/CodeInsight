#include<iostream>
using namespace std;

int main(){
  int n,k,q;
  cin>>n>>k>>q;

  int a[n+1];
  for(int i =0;i<=n;i++) a[i]=0;
  for (int i=0;i<q;i++){
    int x;
    cin>>x;
    a[x]=a[x]+1;
  }

  for(int j=1;j<=n;j++){
    if(q-a[j]<k) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}
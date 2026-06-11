#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int c=0,x,y,z;
  for(int i=0;i<n;i++){
    x=a[i];
    for(int j=i+1;j<n;j++){
        if(a[j]!=a[i]){
            for(int k=j+1;k<n;k++){
                if((a[i]+a[j])>a[k]&&a[k]!=a[j])
                    c++;
            }
        }
    }
  }
  cout<<c<<"\n";
}
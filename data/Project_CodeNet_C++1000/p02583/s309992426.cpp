#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  long long int n[a];
  for(int i=0;i<a;i++){
    cin>>n[i];
  }

  long long int d;
  int m=0;
  for(int i=0;i<a;i++){
    for(int j=0;j<a;j++){
        if(n[i]<n[j]){
            d=n[i];
            n[i]=n[j];
            n[j]=d;
        }
    }
  }
  /**for(int i=0;i<a;i++){
    cout<<n[i]<<endl;
  }**/
  for(int i=0;i<a-1;i++){
    for(int j=i+1;j<a;j++){
        if(n[i]!=n[j]){
        d=n[i]+n[j];
        for(int k=j+1;k<a;k++){
            if(n[k]!=n[i] && n[k]!=n[j])
            {if(d>n[k])
                m++;
            }
        }
        }
    }
  }
  cout<<m;


}

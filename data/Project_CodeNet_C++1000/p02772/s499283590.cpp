#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a[1000], cnt =0, sum=0;
cin>>n;
 for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]%2==0)
        cnt++;
 }
  for(int i=0; i< n; i++){
    if(a[i]%2==0){
        if(a[i]%3==0 || a[i]%5==0)
            sum++;
    }
  }
  if(cnt==sum)
    cout<<"APPROVED";
  else
    cout<<"DENIED";
    return 0;
}


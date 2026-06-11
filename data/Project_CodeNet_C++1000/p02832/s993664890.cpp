#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n],b=0,c=0,x=1,k=-1;
  for(int i=0;i<n;i++)
  cin>>a[i];
  for(int i=0;i<n;i++){
    if(a[i]==x){
        c++;
        x++;
        continue;
    }
    else{
        b++;
        continue;
    }
  }
  if(c==0&&b==n)
    cout<<k;
  else if(c==n)
    cout<<'0';
  else
    cout<<b;
}

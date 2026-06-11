 #include<bits/stdc++.h>
using namespace std;
int main(){
  int n,even=0,count=0;
  cin>>n;
  int a[n];
 
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]%2==0){
      even++;
      if(a[i]%3==0||a[i]%5==0){
      count++;
    }
    }
    
  }
  
  if(even != count)
     cout<<"DENIED"<<endl;
  else
     cout<<"APPROVED"<<endl;
}
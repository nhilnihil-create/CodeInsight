#include<bits/stdc++.h>

using namespace std;

int arr[1000001];

vector<int> vis(1000001,0);

int main(){
   int n;
   cin>>n;
   int mx=0;
   for(int i=0;i<n;i++){
   	cin>>arr[i];
   	mx=max(mx,arr[i]);
   }
   bool flag=false;
   for(int i=0;i<n;i++){
   	  int m=arr[i];
   	  for(int j=1;j<=sqrt(m);j++){
   	  	if(m%j==0){
   	  		vis[j]++;
   	  		if(vis[i]>1&&i!=1){
   	  			flag=true;
   	  			break;
   	  		}
    
   	  		if(j!=m/j){
   	  			vis[m/j]++;
              if(vis[m/j]>1&&m/j!=1){
              flag=true;
              break;}
              
   	  		}
   	  	}
        
   	  }
     if(flag==true){
     break;}
   	  
   }
   
   if(flag==false){
   	cout<<"pairwise coprime"<<endl;
   	return 0;
   }
   int x=__gcd(arr[0],arr[1]);
   for(int i=1;i<n;i++){
   	  x=__gcd(x,arr[i]);
   }
   if(x==1){
   	cout<<"setwise coprime"<<endl;
   }
   else{
   	cout<<"not coprime"<<endl;
   	
   }
}

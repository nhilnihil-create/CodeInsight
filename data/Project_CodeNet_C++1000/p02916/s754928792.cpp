#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,satisfy=0,x,y;
   cin>>N;
  vector<int> a(N);
  vector<int> b(N);
  vector<int> c(N);
 
  for(int i=0;i<N;i++) {
    cin>>a[i]; 
   	//cout<<a[i]<<endl;
  }
  for(int i=0;i<N;i++){
    cin>>b[i];
  	//cout<<b[i]<<endl;
  }
  for(int i=0;i<N-1;i++) {
    cin>>c[i];
  	//cout<<c[i]<<endl;
  }
  
  for(int i=0;i<N;i++){
    x=a[i]-1;
    //cout<<x<<endl;
    satisfy+=b[x];
    //cout<<b[x]<<endl;
    if(a[i]+1==a[i+1]){
      //cout<<"flag"<<endl;
      y=a[i]-1;
      //cout<<c[y]<<endl;
      satisfy+=c[y];
    }
  //  cout<<satisfy<<endl;
  }
  cout<<satisfy<<endl;
}
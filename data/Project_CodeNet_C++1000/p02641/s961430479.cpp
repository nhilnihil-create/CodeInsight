#include<bits/stdc++.h>
using namespace std;
int main(){
 int k,n;
  cin>>k>>n;
  set<int> st;
  int a[n],min=INT_MAX,res;
  if(n==0){
   cout<<k;
    return 0;
  }
  for(int i=0;i<n;i++){
   cin>>a[i];
    st.insert(a[i]);
    if(abs(a[i]-k)<min){
    	min  = abs(a[i]-k);
       res = a[i];
    }
  }
  int i=res+1,j=res-1;
  while(true){
  	if(st.find(j)==st.end()){
      cout<< j ;
      break;
    }
    else if(st.find(i)==st.end()){
      cout<<i;
      break;
    }
    i++,j--;
  }
  
  
  
}

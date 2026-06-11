#include<bits/stdc++.h>
using namespace std;

int main(){
  double s[1000];
  int n;
  
  while(true){
    cin>>n;
    double sum=0;
    if(n==0)break;
    for(int i=0; i<n; i++){
      cin>>s[i];
      sum+=s[i];
    }
    double bunsan=0;
    sort(s,s+n);
    for(int i=0; i<n; i++){
      bunsan += (s[i]-(sum/n))* (s[i]-(sum/n));
    }
    bunsan /= n;
    cout<<fixed<<pow(bunsan,0.5)<<endl;
  }
  
}



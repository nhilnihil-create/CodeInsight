#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  if(N%3!=0){
  bool x=true;
    for(int i=0;i<N;i++)
      if(A.at(i)!=0){x=false; break;}
    if(x)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  
  }else{
  sort(A.begin(),A.end());
    set<int64_t>S1; set<int64_t>S2; set<int64_t>S3;
  int k=N/3;
    for(int i=0;i<k;i++)
      S1.insert(A.at(i));
    for(int i=k;i<(2*k);i++)
      S2.insert(A.at(i));
    for(int i=(2*k);i<N;i++)
      S3.insert(A.at(i));
      int a=S1.size();
    int b=S2.size();
    int c=S3.size();
    if(a!=1 || b!=1 || c!=1)
      cout<<"No"<<endl;
    else{
    int64_t n=A.at(0); int64_t m=A.at(k); int64_t l=A.at(2*k);
      if((n^m^l)==0)
        cout<<"Yes"<<endl;
      else
        cout<<"No"<<endl;
    
    }
  
  
  
  
  }
   return 0;
}

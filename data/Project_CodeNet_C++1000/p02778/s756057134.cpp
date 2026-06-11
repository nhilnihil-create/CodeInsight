    #include <bits/stdc++.h>
     
    using namespace std;
    const long long INF = 1LL <<60;  
     
    long long gcn(long long x,long long y){
      if(x%y==0){
        return y;
      }
      else{
        return gcn(y,x%y);
      }
    }
     
    int main(void){
      long long tmp;
      long long n,k;
      long long i,j;
      string x;
      
      
      cin>>x;
      for(i=0;i<x.length();i++){
        cout<<"x";
      }
            
      cout<<endl;
      return 0;
    }
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
     long long  int n,d;
      cin>>n>>d;
      int count=0;
      while(n--){
         long long   int l=0;
       //  long long   int s=0;
       long long  int x,y;
        cin>>x>>y;
       l = x*x+y*y ;
        //int s=sqrt(x);
        if(l<=d*d)
          count++;}
      cout<<count<<endl;
        
        
    }
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
      long res=0;
      long long n,m;
      long tmp;
      long long i,j,k;
      
      cin>>n;
      long l[n];
      for(i=0;i<n;i++){
        cin>>l[i];
      }
      sort(l,l+n);
      for(i=0;i<n-2;i++){
        //cout<<i<<endl;
        for(j=i+1;j<n-1;j++){
          tmp=l[i]+l[j];
          //cout<<i<<j<<tmp<<endl;
          for(k=j+1;(l[k]<tmp && k<n);k++){
            //cout<<i<<j<<k<<l[i]<<l[j]<<l[k]<<endl;
            if((l[i]+l[k]>l[j]) && (l[j]+l[k]>l[i])){
              res++;
            }
          }
        }
      }
      
      cout<<res<<endl;
      return 0;
    }
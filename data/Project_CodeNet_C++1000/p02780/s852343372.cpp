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
      long double res=0.0;
      long double sum=0.0;
      
      cin>>n>>k;
      long a[n];
      for(i=0;i<n;i++){
        cin>>tmp;
        a[i]=(1+tmp);
        //cout<<a[i]<<endl;
      }
      for(i=0;i<k;i++){
        res+=a[i];
      }
      sum=res;
      //cout<<sum<<endl;
      for(i=k;i<n;i++){
        sum+=a[i]-a[i-k];
        res=max(sum,res);
      }
            
      cout<<scientific<<setprecision(10)<<res/2.0<<endl;
      return 0;
    }
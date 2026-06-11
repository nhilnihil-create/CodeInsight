#include <iostream>
using namespace std;
int main(){
  string s;
  long long k;
  cin>>s>>k;
  long long n=s.size();
  if(s[0]!=s[n-1]){
    long long sum=0;
    for(int i=0;i<n;i++){
      long long cnt=1;
      while(i+1<n&&s[i]==s[i+1]){
        i++;
        cnt++;
      }
      sum+=cnt/2;
    }
    cout<<sum*k<<endl;
  }else{
    bool f=true;
    for(int i=0;i+1<n;i++){
      if(s[i]!=s[i+1]){
        f=false;
      }
    }
    if(f){
      cout<<n*k/2<<endl;
    }else{
      long long l=0;
      while(s[l]==s[l+1]){
        l++;
      }
      long long r=n-1;
      while(s[r]==s[r-1]){
        r--;
      }
      l++;
      r--;
      long long hoge=n-1-r+l;
      long long sum=0;
      sum+=l/2;
      sum+=(n-1-r)/2;
      while(l<=r){
        long long cnt=1;
        while(s[l]==s[l+1]){
          l++;
          cnt++;
        }
        l++;
        sum+=(cnt/2)*k;
      }
      sum+=(hoge/2)*(k-1);
      cout<<sum<<endl;
    }
  }
  return 0;
}

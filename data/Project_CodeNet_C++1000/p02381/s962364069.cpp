#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int n;
  double avg,ans,a[1001];

  while(cin >> n,n){
    
    avg = 0;
    ans = 0;
    for(int i = 0;i < n;i++){
      cin >> a[i];
      avg += a[i];
    }
    avg = avg/n;
    
    for(int i = 0;i < n;i++){
      ans += pow((a[i]-avg),2);
    }

    printf("%.8f\n",sqrt(ans/n));
  }
  
  return (0);
}
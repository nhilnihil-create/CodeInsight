#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[10][10];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++){int x,r;
        x=i;
        r=x%10;
        while(x>=10) 
           x/=10;
        arr[r][x]++;
    }
    int ans = 0;
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
        ans+=arr[i][j]*arr[j][i];
      }
    }
    cout<<ans<<"\n";
}


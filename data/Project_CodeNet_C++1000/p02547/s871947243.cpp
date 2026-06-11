#include<bits/stdc++.h>
using namespace std;
int a[100][2];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,count=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
      cin>>a[i][0]>>a[i][1];
    }
    for (int i = 0; i < n; i++)
    {
      if(a[i][0]==a[i][1]){
          count++;
      }else
      {
          count=0;
      }
      if(count==3){
          cout<<"Yes"<<endl;
          return 0;
      }
    }
    cout<<"No"<<endl;
}
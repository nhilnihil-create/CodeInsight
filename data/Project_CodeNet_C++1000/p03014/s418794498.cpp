#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod ll(1e9+7)
#define inf ll(1e9)
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
   int h,w;
   cin>>h>>w;
   vector<string>arr(h);
   for(int i=0; i<h; i++)
    cin>>arr[i];
   vector<vector<int> >mtr1(h,vector<int>(w)),mtr2(h,vector<int>(w));
   for(int i=0; i<h; i++){
    int sum=0;
    for(int j=0; j<w; j++){
      if(arr[i][j]=='.'){
        sum++;
        mtr1[i][j]=sum;
      }
      else{
        sum=0;
      }
    }
    int temp=0;
    for(int j=w-1; j>=0; j--){
      if(arr[i][j]=='.' && temp==0){
        temp=mtr1[i][j];
      }
      else if(arr[i][j]=='.'){
        mtr1[i][j]=temp;
      }
      else
        temp=0;
    }
   }
   for(int i=0; i<w; i++){
    int sum=0;
    for(int j=0; j<h; j++){
      if(arr[j][i]=='.'){
        sum++;
        mtr2[j][i]=sum;
      }
      else
        sum=0;
     }
     int temp=0;
     for(int j=h-1; j>=0; j--){
      if(arr[j][i]=='.' && temp==0){
        temp=mtr2[j][i];
      }
      else if(arr[j][i]=='.'){
        mtr2[j][i]=temp;
      }
      else
        temp=0;
     }
   }
   int ans=0;
   for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      ans=max(ans,mtr1[i][j]+mtr2[i][j]-1);
    }
   }
   cout<<ans;
   return 0;
   
}
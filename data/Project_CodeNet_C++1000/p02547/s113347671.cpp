# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int arr[101]={};
int main(){
  ll n;cin>>n;
  int d1,d2;
  for(int i=1;i<=n;i++){
    cin>>d1>>d2;
    if(d1==d2){
      arr[i]++;
    }
  }
  for(int i=1;i<=n-2;i++){
    if(arr[i]+arr[i+1]+arr[i+2]==3){
      cout<<"Yes";
      return 0;
    }
  }cout<<"No";
}

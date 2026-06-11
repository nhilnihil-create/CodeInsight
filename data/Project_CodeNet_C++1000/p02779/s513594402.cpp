# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int main(){
 int n;cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
  cin>>arr[i];
sort(arr,arr+n);
for(int i=0;i<n-1;i++){
  if(arr[i]==arr[i+1]){
      cout<<"NO";
      break;}
  if(i==n-2)
      cout<<"YES";
}
  return 0;
}

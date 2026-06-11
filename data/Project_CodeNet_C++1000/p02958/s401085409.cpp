# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int arr[51];
int main(){
  int n,cp=0;cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    if(arr[i]!=i)
      cp++;
  }
  if(cp<=2)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}

#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define mo 1000000007
using namespace std;
//Conditional Operator (condition?true part:false part) eg : cout<<(y<=3?"YES":"NO")<<endl;a
ll getmul(ll n){ll int k{0};while(n>0){k+=n%10;n=n/10;}return k;}//Sum OF n DIGITS
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int sum{0};
  for(int i=1;i<=n;i++){
    if(arr[i-1]%2!=0&&i%2!=0)
      sum++;
  }
  cout<<sum<<endl;
 return 0; 
}
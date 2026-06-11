#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(int a,int b){
  return a<b;//ascending
} 

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


    int n,x,t;
    cin>>n>>x>>t;
    int naya=0;
    int count=0;
    while(naya<n){
      naya+=x;
      count++;
    }
    cout<<t*count<<endl;

  return 0;
}
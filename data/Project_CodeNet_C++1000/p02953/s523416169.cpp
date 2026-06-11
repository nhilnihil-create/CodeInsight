#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
   int n;
   cin>>n;
   vector<ll> h(n);
   rep(i,n) cin>>h[i];
   h[0]--;
   rep(i,n-1){
       if(h[i]<h[i+1]) h[i+1]--;
       if(h[i]>h[i+1]){
           cout<<"No"<<endl;
           return 0;
       }
   } 
   cout<<"Yes"<<endl;
}
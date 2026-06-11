#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(int a,int b){
  return a<b;//ascending
} 

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


    int d,t,s;
    cin>>d>>t>>s;
  double k=(double)d/s;
    if((k)<=t){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }


  return 0;
}
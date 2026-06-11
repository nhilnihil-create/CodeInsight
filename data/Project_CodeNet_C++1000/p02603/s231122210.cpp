#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define p push_back
#define endl "\n"
#define l long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    l n,stock=0,rs=1000 ;
    cin>>n;
    vector<l>v;
    for(l i=0;i<n;i++){
        l s;
        cin>>s;
        v.p(s);
    }
    vector<l>::iterator start; 
    start = unique(v.begin(), v.begin() + v.size());
    v.resize(std::distance(v.begin(), start)); 
    for(l i=0;i<v.size()-1;i++){
        if(v[i]<v[i+1]){
            // buy
          if(rs>v[i]){
            stock+=rs/v[i];
            rs-=stock*v[i];
          }
        }
        else{
            // sell
            rs+=stock*v[i];
            stock=0;
        }
    }
  if(stock!=0){
   	 rs+=v[v.size()-1]*stock;
    stock=0;
  }
    cout<<rs;
    return 0;
}

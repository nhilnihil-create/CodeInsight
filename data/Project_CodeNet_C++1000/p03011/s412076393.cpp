#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;


int main(){
int p,q,r;
cin>>p>>q>>r;
if(p>q){
if(p<r){
cout<<p+q;
return 0;
}else{
cout<<r+q;
return 0;
}

}else{
if(q<r){
cout<<p+q;
return 0;
}else{
  cout<<p+r;
return 0;  
}
}



}
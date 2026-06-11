#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
    int p,q,r;
    cin>>p>>q>>r;
    int ans=0;
    int a,b;
if(p<q){
if(q<r){
a=p;b=q;
}else{
a=p;b=r;
}
}else{
if(p<r){
a=p;b=q;
}else{
a=r;b=q;
}
}
ans=a+b;
cout<<ans;

}
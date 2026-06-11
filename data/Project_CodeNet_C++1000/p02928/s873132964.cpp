#include<bits/stdc++.h>
using namespace std;
int p = 1e9+7;
int add(int a,int b){
    int s=(a+b);
    if(s>=p)s-=p;
    return s;
}
int sub(int a,int b){
    int s=(a+p-b);
    if(s>=p)s-=p;
    return s;
}
int mul(int a,int b){
    return (1LL*a*b)%p;
}
int po(int a,int deg){
    
    if(deg==0)return 1;
    int temp = po(a,deg/2);
    temp = mul(temp,temp);
    if(deg%2!=0)temp=mul(temp,a);
    return temp;
    
}
int inv(int n){
    return po(n,p-2);
}
int main(){
	int n,k;cin>>n>>k;
  vector<int >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  //for every number find the number of numbers less on both left and right side
  int right=0,left=0;
  for(int i=0;i<n;i++){
  	int count=0;
    for(int j=i-1;j>=0;j--)if(nos[j]<nos[i])count++;
    left=add(left,count);
    count=0;
    for(int j=i+1;j<n;j++)if(nos[j]<nos[i])count++;
    right=add(right,count);
  }
  //cout<<right<<' '<<left<<'\n';
  int invnos=0;
  invnos = add(invnos,mul(right,mul(mul(k,k+1),inv(2)   )  ) );
    invnos = add(invnos,mul(left,mul(mul(k-1,k),inv(2)   )  ) );
  cout<<invnos;
}
//take any number for instance
//which is in the nth iteration
//consider only right
//me  + 2*me + me3 + .. me*k
//now consider left
//me  + .. (k-1)*me;
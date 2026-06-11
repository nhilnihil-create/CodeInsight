#include<bits/stdc++.h>
using namespace std;
int p = 1e9+7;
const int N = 2e6;
vector<int >fact(N);
vector<int >invf(N);

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
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i] = mul(fact[i-1],i);
    invf[N-1]=inv(fact[N-1]);
    for(int i=N-2;i>=0;i--)invf[i] = mul(invf[i+1],i+1);
	long long x,y;cin>>x>>y;
  if((2*x-y)%3==0 && (2*y-x)%3==0){
    long long a,b;
  	b = (2*x-y)/3;
    a = (2*y-x)/3;
    if(a<0 || b<0){cout<<0;return 0;}
    cout<<mul(fact[a+b],mul(invf[a],invf[b]));
  }
  else cout<<0;
}
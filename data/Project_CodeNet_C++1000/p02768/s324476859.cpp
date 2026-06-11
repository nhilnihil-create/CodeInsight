#include<bits/stdc++.h>
using namespace std;
int p = 1e9+7;
const int N = 2e5+4;
vector<int >fact(N);
//vector<int >invf(N);
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
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i] = mul(fact[i-1],i);
    //invf[N-1]=inv(fact[N-1]);
    //for(int i=N-2;i>=0;i--)invf[i] = mul(invf[i+1],i+1);
	int n,x,y;cin>>n>>x>>y;
	int temp1=1,temp2=1;
	for(int i=0;i<x;i++)temp1 = mul(temp1,n-i);
	for(int i=0;i<y;i++)temp2 = mul(temp2,n-i);
	int onechan = mul(temp1,inv(fact[x]));
	int dochan = mul(temp2,inv(fact[y]));
    cout<<sub(po(2,n),add(1,add(onechan,dochan)));
}
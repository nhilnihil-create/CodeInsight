//a b c d - b/w a and b, not evenly divided by c or d
//answer = totalbyc+totalbyd-totalbycandd
//final = b-a+1-answer
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long c, long long d){
    if(d==0)return c;
    else return gcd(d,c%d);
}
long long lcm(long long c,long long d){
    //cout<<gcd(c,d)<<endl;
    return (c*d)/gcd(c,d);
}
int main(){
	long long a,b,c,d;
  cin>>a>>b>>c>>d;
  //first number divisibly by c
  //a+(c-a%c);b-b%c -
  long long first ;
  long long last ;
  long long total = 0;
  long long div;
  for(int i=0;i<3;i++){
    if(i==0)div=c;
    if(i==1)div=d;
    if(i==2){div = lcm(c,d);}
  	if(a%div!=0)first = a + div-a%div;
    else first = a;
    last = b - b%div;
    if(first>last || first>b || last<a)continue;
    if(i!=2){total+=(last-first)/div+1;}
    else {total-=(last-first)/div+1;}
  }
  cout<<b-a+1-total;
}
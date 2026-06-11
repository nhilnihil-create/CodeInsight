#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long int gcd(long long int a,long long int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int main(){
    long long int A,B,C,D;
    cin>>A>>B>>C>>D;
    long long int ans=0;
    ans=B-A+1;
    ans-=(B/C)-((A-1)/C);
    ans-=(B/D)-((A-1)/D);
    long long int sai=(C*D)/gcd(C,D);
    ans+=(B/sai)-((A-1)/sai);
    cout<<ans<<endl;
    return 0;
}

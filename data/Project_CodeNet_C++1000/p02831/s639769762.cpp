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
    long long int A,B;
    cin>>A>>B;
    long long int ans=A*B/gcd(A,B);
    cout<<ans<<endl;
    return 0;
}

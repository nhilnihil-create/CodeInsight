/*
* ID: juryc
* PROG: Snake
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lcm(a,b) ((a)*(b))/(__gcd(a,b))
int main(){
ll a,b; cin>>a>>b;
cout<<lcm(a,b)<<endl; 
return 0;
}
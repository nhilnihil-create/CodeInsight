#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
ll n;cin>>n;
ll div=n/1000;
(n%1000==0)?cout<<0:cout<<((div+1)*1000)-n;
}

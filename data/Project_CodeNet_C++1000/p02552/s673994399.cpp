#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a;}
int main(){
ll a;
while(cin>>a){

if(a==0)cout<<"1"<<endl;
else cout<<"0"<<endl;
}


	return 0;
}
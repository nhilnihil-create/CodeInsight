/******************************************
* AUTHOR : SOMU KUMAR *
* INSTITUTION : IIT BHUBANESWAR *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
//code here...............//
int x;
cin>>x;
if(x>=400&&x<600)cout<<8<<endl;
if(x>=600&&x<800)cout<<7<<endl;
if(x>=800&&x<1000)cout<<6<<endl;
if(x>=1000&&x<1200)cout<<5<<endl;
if(x>=1200&&x<1400)cout<<4<<endl;
if(x>=1400&&x<1600)cout<<3<<endl;
if(x>=1600&&x<1800)cout<<2<<endl;
if(x>=1800&&x<2000)cout<<1<<endl;

return 0;
}
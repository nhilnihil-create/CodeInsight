/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
#define ll 	long long
#define pb push_back
#define mp make_pair
using namespace std;

int main() {

ll n; cin>>n;
ll d=100;
ll cnt=0;
while(d<n)
{
	
	d+=d/100;
	cnt++;
	//if(d==n)
	//break;
	
}
cout<<cnt<<endl;
    return 0;
}
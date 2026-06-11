#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
ll ar[sz];

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#endif

string s;
cin>>s;
if(s=="SUN") cout<<"7"<<endl;
if(s=="MON") cout<<"6"<<endl;
if(s=="TUE") cout<<"5"<<endl;
if(s=="WED") cout<<"4"<<endl;
if(s=="THU") cout<<"3"<<endl;
if(s=="FRI") cout<<"2"<<endl;
if(s=="SAT") cout<<"1"<<endl;

}
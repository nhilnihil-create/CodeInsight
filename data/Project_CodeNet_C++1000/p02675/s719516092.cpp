 #include <bits/stdc++.h>

#include<stdlib.h>
#include<iostream>
#include<math.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define INF 2000000000
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define PI 3.1415926535897932
using namespace std;

int main()
{
IOS;
int t;
cin>>t;
if(t%10==2||t%10==4||t%10==5||t%10==7||t%10==9)
	cout<<"hon";
else if(t%10==0||t%10==1||t%10==6||t%10==8)
	cout<<"pon";
else
	cout<<"bon";




return 0;
}
#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	 long long int x,r,p,m,s;
 	 cin>>x;
 	 p=x/500;
 	 r=x%500;
 	 m=r/5;
 	 s=p*1000+m*5;
 	 cout<<s<<endl;
 	return 0;
 }
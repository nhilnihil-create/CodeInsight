#include<bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int main()
{
 fastIO();
 long long x , temp , year;
 cin>>x;
 temp = 100;
 year = 0;
 
 while(temp<x)
 {
 	temp = temp+(temp/100);
 	year++;
 }
 
 //cout<<"total year " << year<<endl;
 
 cout<<year<<endl;
 
 
 
 

return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ll a,b,c,k;
 cin>>a>>b>>c;
 k=c-a-b;
 if(k>0 && k*k>4*a*b)
 {
     cout<<"Yes"<<endl;
 }else{
     cout<<"No"<<endl;
 }
}

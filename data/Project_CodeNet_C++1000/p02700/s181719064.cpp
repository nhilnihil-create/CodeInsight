#include<bits/stdc++.h>
using namespace std;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int a,b,c,d;    cin>>a>>b>>c>>d;

while(a>0 && c>0)
{
   c=c-b; if (c<=0) {cout<<"Yes"<<endl; break;}
   a=a-d; if (a<=0) {cout<<"No"<<endl; break;}

}










return 0;}

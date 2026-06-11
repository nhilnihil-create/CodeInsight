#include<bits/stdc++.h>
using namespace std;
int main(){
int a1,b1,a2,b2,k,s=0;
cin>>a1>>b1>>a2>>b2>>k;
if(b1>b2)s=(a2-1-a1)*60+60+b2-b1;
else s=(a2-a1)*60+b2-b1;
cout<<s-k;
return 0;
}

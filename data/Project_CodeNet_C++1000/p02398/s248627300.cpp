#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,c,i,d;
cin>>a>>b>>c;
for(i=a;;i++){
	if(c%i==0){d++;}
	if(i==b){break;}
	}
cout<<d<<endl;
return 0;
}

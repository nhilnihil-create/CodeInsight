#include<bits/stdc++.h>
using namespace std;
int main(){
 int a,b,c,tmp;
 cin >> a >> b >>c;
 tmp=a;
 a=b;
 b=tmp;
  
 tmp=a;
 a=c;
 c=tmp;
 
 cout<<a<<" "<<b<<" "<<c<<endl;
}

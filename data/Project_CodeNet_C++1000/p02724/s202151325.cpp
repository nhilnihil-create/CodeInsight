#include <bits/stdc++.h>
using namespace std;
int main(){

int n,a,b,sum=0;
cin>>n;
a=n/500;
b=n%500;
b=b/5;
sum=a*1000+b*5;

cout<<sum<<endl;

return 0;

}

#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
cin>>a>>b>>c;
int m;
m=max(max(a,b),c);
cout<<a+b+c-m<<endl;

}
#include<bits/stdc++.h>
using namespace std;

int main(){

cout<<fixed<<setprecision(12);
double a,b,c,d;
cin>>a>>b>>c>>d;
double X=pow(c-a,2);
double Y=pow(d-b,2);
cout<<sqrt(X+Y)<<endl;


return 0;
}

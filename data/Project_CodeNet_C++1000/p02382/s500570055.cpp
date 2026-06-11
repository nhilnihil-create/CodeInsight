#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){

int n;
cin>>n;

double x[n];
double y[n];

for(int i=0;i<n;i++){
cin>>x[i];
}
for(int i=0;i<n;i++){
cin>>y[i];
}

double p1=0;

for(int i=0;i<n;i++){
p1 = p1 + fabs(x[i]-y[i]);
}

double p2=0;

for(int i=0;i<n;i++){
p2 = p2 + pow(fabs(x[i]-y[i]),2);
}

p2 = sqrt(p2);

double p3=0;

for(int i=0;i<n;i++){
p3 = p3 + pow(fabs(x[i]-y[i]),3);
}

p3 = pow(p3,0.3333333333);

double pz=0;
double check=0;

for(int i=0;i<n;i++){
check=fabs(x[i]-y[i]);
if(pz<=check)pz=check;
}

cout<<fixed<<p1<<endl;
cout<<fixed<<p2<<endl;
cout<<fixed<<p3<<endl;
cout<<fixed<<pz<<endl;
}

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){

int n;

while(1){

double inputsum=0;
double average=0;
double sum=0;

cin>>n;
if(n==0)break;
double s[n];
double hensa[n];
double haverage=0;

for(int i=0;i<n;i++){
    hensa[i]=0.0;
    s[i]=0.0;
}
for(int i=0;i<n;i++){
cin>>s[i];
inputsum=inputsum+s[i];

}

average=inputsum/n;

for(int i=0;i<n;i++){
hensa[i]=s[i]-average;
}

for(int i=0;i<n;i++){
haverage=haverage+pow(hensa[i],2);
}

haverage=haverage/n;

sum=sqrt(haverage);

cout<<fixed<<sum<<" "<<endl;

}

}

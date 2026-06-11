#include <iostream>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
set<long long> s;
double h,n;
cin>>h>>n;

long long sum=0;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    sum+=a;
}
if(sum>=h)
cout<<"Yes";
else
cout<<"No";
}


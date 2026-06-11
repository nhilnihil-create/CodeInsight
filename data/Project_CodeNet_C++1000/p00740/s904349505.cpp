#include<iostream>
using namespace std;
main(){int n,p;while(cin>>n>>p&&n&&p){int num=0,p2=p,a[50]={};while(a[(num-1)%n]!=p){if(p2)p2--,a[num%n]++;else p2=a[num%n],a[num%n]=0;num++;}cout<<(num-1)%n<<endl;}}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define PI acos(-1)
int main(){
int a,b;
while(cin>>a>>b,a||b){
rep(i,a){
rep(j,b){
if(i==0||i==a-1||j==0||j==b-1)cout<<"#";
else cout<<".";
}
cout<<endl;
}
cout<<endl;
}
}
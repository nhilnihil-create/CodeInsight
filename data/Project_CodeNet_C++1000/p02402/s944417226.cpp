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
int n;
cin>>n;
vector<int>in(n);
long long int sum=0;
rep(i,n){cin>>in[i];sum+=in[i];}
sort(in.begin(),in.end());
cout<<in[0]<<" "<<in[n-1]<<" "<<sum<<endl;
}
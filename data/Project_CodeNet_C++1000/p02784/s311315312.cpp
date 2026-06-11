#include<iostream>
#include<stdio.h>
using namespace std;
using ll=long long;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)
using P=pair<int,int>;
const int mod=1000000007;

int main(){
ll h,s;
int n;
ll sum=0;
cin>>h>>n;
rep(i,n){cin>>s;
sum+=s;
}
if(sum>=h)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}


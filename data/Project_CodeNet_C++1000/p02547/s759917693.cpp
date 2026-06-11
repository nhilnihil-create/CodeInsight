#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int main(){int n,D1,D2;int res=0;cin >> n;rep(i,n){cin>>D1>>D2;if(D1==D2)res+=1;else res=0; if(res==3){cout<<"Yes"<<endl;return 0;}}cout<<"No"<<endl;return 0;}
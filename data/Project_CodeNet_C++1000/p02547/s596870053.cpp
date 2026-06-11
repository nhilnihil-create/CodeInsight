#include <bits/stdc++.h>
using namespace std;
int main(){int n,i,r=0;cin>>n;int D,F;for(i=0;i<n;i++){cin>>D>>F;if(D==F)r++;else r=0;if(r==3){cout<<"Yes"<<endl;return 0;}}cout<<"No"<<endl;return 0;}
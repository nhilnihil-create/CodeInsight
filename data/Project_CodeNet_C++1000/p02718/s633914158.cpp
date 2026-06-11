#include <bits/stdc++.h>
using namespace std;
#define     LL      long long int
vector<int>v,vv;

int main()
{
    int n,a[106],sum=0,num=0,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]*m*4>=sum){
            num++;
        }
    }
    if(num>=m){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
     return 0;
}

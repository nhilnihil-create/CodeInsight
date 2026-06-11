#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int x,y;cin>>x>>y;
    x=min(x,4);
    y=min(y,4);
    int m[]={0,3,2,1,0};
    int ans=0;
    if(x==1&&y==1) ans+=4;
    ans+=m[x]+m[y];
    cout<<ans*100000<<endl;
}
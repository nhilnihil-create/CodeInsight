#include <bits/stdc++.h>
using namespace std;
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
int fr[205];
int main()
{   init();
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    int a;
    cin>>a;
    if(a%2==1&&i%2==1)ans++;}
    cout<<ans;
}

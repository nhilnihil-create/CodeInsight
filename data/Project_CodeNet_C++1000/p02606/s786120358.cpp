#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;


int main()
{
    int l,r,d,ans=0;cin>>l>>r>>d;
    for(int i=l;i<=r;i++){
        if(!(i%d)) ans++;
    }
    cout<<ans;
    return 0;
}
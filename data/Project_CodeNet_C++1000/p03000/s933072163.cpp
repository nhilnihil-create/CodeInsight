#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int ans=1;
    int lx=0;
    int l[n];
    for(int i=0;i<n;i++){
        cin>>l[i];
        lx+=l[i];
        if(lx>x)break;
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}
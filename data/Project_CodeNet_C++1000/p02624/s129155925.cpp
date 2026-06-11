#include<bits/stdc++.h>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	long long ans=0;
	int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            ans+=j;
        }
    }
    cout<<ans<<endl;

    return 0;
}
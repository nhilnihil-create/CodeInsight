#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+9;
const int mod=1e9+7;

ll a[N],b[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,c,ans,ans1;
    map<int,int>cnt;
    cin>>x>>n;
    while(n--){
    	cin>>c;
    	cnt[c]++;
    }
    for(int i=x; ;i++){
    	if(cnt[i]==0){
    		ans=i;
    		//cout<<ans;
    		break; 
    	}
    }
    for(int i=x-1; ;i--){
    	if(cnt[i]==0){
    		ans1=i;
    		break; 
    	}
    }
    if(abs(ans-x)<abs(ans1-x)){
    	cout<<ans;
    }
    if(abs(ans-x)>abs(ans1-x)){
    	cout<<ans1;
    }
    if(abs(ans-x)==abs(ans1-x)){
    	cout<<min(ans,ans1);
    }

}

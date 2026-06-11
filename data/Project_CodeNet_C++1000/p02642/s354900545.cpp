#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+9;
const int mod=1e9+7;
const int M=1e6+9;

map<int,int>cnt,vis;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int ans=n;
    int tot=n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	cnt[a[i]]++;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
    	int cur=a[i];
    	if(cnt[cur]==0)continue;
    	for(ll j=cur;j<=M;j+=cur){
    		if(cnt[j]>0){
    			if(j==cur){
    				if(cnt[j]>1){
    				ans-=cnt[j];
    				cnt[j]=0;
    			   }
    			}
    		    else {
                    if(cnt[j]>0){
	    				ans-=cnt[j];
	    				cnt[j]=0;
	    				//cout<<cur<<" "<<j<<endl;
    				} 
    			}
    		}
    	}
    }
    cout<<ans<<'\n';
   

    
    
   

}
    
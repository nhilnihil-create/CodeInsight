#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	 ios_base::sync_with_stdio(false);
	  cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> s(m);
    vector<int>p(m);
    for(int i=0;i<m;i++) cin>>p[i]>>s[i];
    int val[n+1]={0};
   int cor[n+1]={0};
    for(int i=0;i<m;i++){
    	if(s[i]=="AC"){
    		cor[p[i]]=1;
		}
		else{
       if(cor[p[i]]==0)			val[p[i]]--;
		}
	}
	int ans=0,pen=0;
	for(int i=1;i<=n;i++){
		if(cor[i]) ans++;
	 if(cor[i])	pen +=abs(val[i]); 
	}
	cout<<ans<<" "<<pen<<"\n";
}
#include<iostream>
#include<vector>
using namespace std; 
int main(){
unsigned long long int n,m,k,i,x,pk, pans=0, mx=0,mxn=0, mxm=0;	
vector<unsigned long long int> nv;
vector<unsigned long long int> mv;
cin>>n>>m>>k;pk=k;
bool pv=true;
for(i=1; i<=n; i++){
	cin>>x; nv.push_back(x);
	if(pv==true){
		if(x<=pk){
		pk-=x; pans++;	
		mxn=i;
		}else{
		if(pans>mx)mx=pans;
			pv=false;
		}
	}
}
pv=true;
for(i=0; i<m; i++){
	cin>>x; mv.push_back(x);
	if(pv==true){
		if(x<=pk){
		pk-=x; pans++;	
		mxm=i+1;
		}else{
			if(pans>mx)mx=pans;
			pv=false;
		}
	}
}
if(pans>mx)mx=pans;

while(mxn>0&&mxm<m){
pk+=nv[mxn-1];pans--;
while(mxm<m&&mv[mxm]<=pk){
	pk-=mv[mxm];pans++;mxm++;
}
mxn--;
if(pans>mx)mx=pans;	
}

cout<<mx;
}
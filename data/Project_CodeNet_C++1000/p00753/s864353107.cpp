#include<bits/stdc++.h>
using namespace std;
#define Max 500000
vector<int> prim;
vector<bool> res(Max+1,true);
void aris(int n){
res[0]=res[1]=false;
	for(int i=2;i<=n;i++){
		if(res[i]){
			prim.push_back(i);
			int k=2;
			while(i*k<=n){
			res[i*k]=false;
			k++;
			}
		}
	}
	return ;
}

int main(){
int n,p;

aris(Max);
while(1){
cin>>n;
if(n==0)break;
int ans=0;
for(int i=n+1;i<=2*n;i++)
if(res[i])ans++;
cout<<ans<<endl;
		}
return 0;
}


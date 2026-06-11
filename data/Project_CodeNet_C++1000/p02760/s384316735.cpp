#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int ls[3][3];vector<int> up(101,0);
	for(int u=0;u<3;u++){
		for(int v=0;v<3;v++){
			cin>>ls[u][v];}}
	int u,v,an=0,n,f=1;cin>>n;
	while(n--){
		int a;cin>>a;up[a]=1;}
	for(u=0;u<3;u++){f=1;
		for(v=0;v<3;v++){
					if(!up[ls[v][u]]){f=0; break;}}
					an+=f;if(an)break;}
	for(u=0;u<3;u++){f=1;
		for(v=0;v<3;v++){
					if(!up[ls[u][v]]){f=0; break;}}
					an+=f;if(an)break;}f=1;
		for(u=1;u<3;u++) if(!up[ls[u][u]]) f=0;
		if(f) an++;
		if(up[ls[1][1]]&&up[ls[0][2]]&&up[ls[2][0]]) an++;
		cout<<(an? "Yes":"No");
}

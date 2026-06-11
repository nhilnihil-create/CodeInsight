#include<bits/stdc++.h>
using namespace std;
int main(){
	int taka_health,taka_strength;
	cin>>taka_health>>taka_strength;
	int aoki_health,aoki_strength;
	cin>>aoki_health>>aoki_strength;
	
	int taka_hit = taka_health/aoki_strength;
	if(taka_health%aoki_strength)taka_hit++;
	int aoki_hit = aoki_health/taka_strength;
	if(aoki_health%taka_strength) aoki_hit++;
	if(taka_hit>=aoki_hit) cout<<"Yes";
	else cout<<"No";
	
}
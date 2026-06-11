#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int lli;
const long long int MaxN=500005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli arr[MaxN];
	char inicio[3]={'r','s','p'};
	map <char,char> counter;	
	map <char,lli> indice;
	lli precio[3];
	void solve(){
		lli N,K,A,B,C,i,j,tot=0,ind,res=0,c,candidato;
		char ant;
		cin>>N>>K;
		cin>>A>>B>>C;
		precio[0]=A,precio[1]=B,precio[2]=C;
		string s;
		counter['s']='r',counter['p']='s',counter['r']='p';
		indice['r']=0,indice['s']=1,indice['p']=2;
		cin>>s;
		for(i=0;i<K;i++){	
			candidato=0;
			for(c=0;c<3;c++){
				tot=0;
				ant=inicio[c];
				if(counter[s[i]]==ant)tot+=precio[c];
				for(j=i+K;j<N;j+=K){
					if(ant==counter[s[j]]){
						ant='a';
					}
					else {
						ant=counter[s[j]];
						tot+=precio[indice[ant]];
					}
				}
				candidato=max(tot,candidato);
				//cout<<tot<<" "<<inicio[c]<<" ";
			}	
			//cout<<"\ncandidato fue "<<candidato<<" "<<i<<"\n";
			res+=candidato;
		}
		cout<<res;
	}
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}

/*
//SOCS1:
#include <stdio.h>
#define ci(x) scanf("%d",&x);
#define cis(x) scanf("%s",&x);
#define cid(x) scanf("%f",&x);
#define cou(x) printf("%d",x);
#define cos(x) printf("%s",x);
#define cof(x) printf("%f",x);
//SOCS1: ( Tambahan, Bila Diperlukan )
#include <string>
#include <vector>
#include <algorithm>
//*/

///*
//CP:
#include<bits/stdc++.h>
using namespace std;
//highlight color RGB = [70,70,70]
#define asll unsigned long long
#define ll long long
#define ld long double
#define imt int
#define pii pair<int,int>
#define st first
#define nd second
#define kj <<" "<<
#define kjb <<" ";
#define dg <<","<<
#define ml <<endl;
#define co cout<<
#define ter cout<<endl;
#define sibi cout<<"TES"<<endl;
#define tes(x) cout<<"TES "<<x<<endl;
#define psbk(x) push_back(x);
#define For(x,a,b) for(int x=(a);x<(b);x++)
#define FOR(x,n) for(int x=0;x<(n);x++)
#define kera(x,m) for( int i = 0;i < m ; i++ ){ cout<<"x["<< i <<"] =" kj x[i] ml}
#define kpr(x) cout<<"("<<x.st dg x.nd <<")" ml
#define kkor(p) cout<<"("<<p.x dg p.y <<")" ml
#define m_p make_pair


#define dekar(b,x) int x[b];
#define gabung(x,p,q) void gab(int p,int q){p=cw(p);q=cw(q);x[p]=q;}
#define cariWakil(x,a) int cw(int a){ if(a==x[a]){ return a;} else{return x[a]=cw(x[a]);}}
#define init_dsu(b,x) void init_djs(){FOR(i,b){x[i]=i;}}
#define priksa(x,p,q) int cek(int p ,int q ){return x(p)==x(q);}
#define paket_djs(nama,b) dekar(b,nama)  init_dsu(b,nama)  cariWakil(nama,a)  gabung(nama,p,q)  priksa(cw,p,q)
 
paket_djs(induk,100005);
asll M=1e9+7;
int n,m,tc;
int p,q,r;
int frek[100005];
//*/

int main()
{
	//CP:
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(0);
	//srand(time(0));
	init_djs();
	cin>>n>>m;
	FOR(i,m){
		cin>>p>>q;
		gab(p,q);
		//tgb[p]=1;
		//tgb[q]=1;
	}
	int hitung=0,sampah,tbs=0,itbs;
	For(i,1,n+1){
		sampah=cw(i);
		//co "is" kj i kj sampah ml
		frek[i]=0;
	}
	For(i,1,n+1){
		frek[induk[i]]++;
	}
	For(i,1,n+1){
		//co "i,frek" kj i kj frek[i] ml
		if(tbs<frek[i]){
			tbs=frek[i];
			itbs=i;
		}
	}
	For(i,1,n+1){
		if(i!=itbs && frek[i]!=0){
			hitung++;
		}
	}
	co hitung ml
}

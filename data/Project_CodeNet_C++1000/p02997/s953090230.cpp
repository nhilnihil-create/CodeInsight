#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);

int main(){
 IOS
 ll n,k;
 cin>>n>>k;
 if(n==2){
 	if(k==0) {
 		cout<<1<<endl;
 		cout<<1<<" "<<2<<endl;
 	}
 	else cout<<-1<<endl;
 	return 0;
 }
 if(k>((n-1)*(n-2))/2) {
 	cout<<-1<<endl;
 	return 0;
 }
 ll total_da=((n-1)*(n-2))/2;
 //dbg(total_da);
 ll curr=0;
 ll extra=((n-1)*(n-2))/2-k;
 ll this_day=n-2;
 ll node=2;
 ll tmp;
 //dbg(extra);
 ll check=0;
 std::vector<pair<ll,ll>> edges;
 while(true){
 	if(curr==extra) break;
 	if(curr+this_day<extra){
 		
 		FOR(i,1,this_day){
 			edges.pb({node,node+i});
 			check++;
 		}
 		curr+=this_day;

 	}
 	else {
 		tmp=extra-curr;
 		FOR(i,1,tmp){
 			edges.pb({node,node+i});
 			check++;
 		}
 		break;

 	}
 	//dbg(curr);
 	node++;
 	this_day--;
 	if(curr==extra) break;

 }
  //dbg(check);
  ll total_edges=sz(edges);

 FOR(i,2,n){
 	total_edges++;
 	

 }
 cout<<total_edges<<endl;
 FOR(i,2,n){
 	
 	cout<<1<<" "<<i<<endl;

 }
 for(auto kk:edges){
 	cout<<kk.first<<" "<<kk.second<<endl;
 }


}
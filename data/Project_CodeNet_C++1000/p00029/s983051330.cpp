#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
vector<vector<char> >tmp;
vector<vector<int> >scr;
int main(){
	string s;
	string nagai;
	int naga=0;
	map<string,int>m;
	while(cin>>s){
		if(naga<s.size()){naga=s.size();nagai=s;}
		//cout<<naga<<" "<<s.size()<<endl;
		m[s]++;
	}
	int ma=-1;
	string mas;
	map<string,int>::iterator it=m.begin();
	
	for(;it !=m.end();it++){
		string t=it->first;
		if(ma<m[t]){ma=m[t];mas=t;}
	}
	cout<<mas<<" "<<nagai<<endl;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	map <int,int> hn,wn;
	int hm=0,wm=0;
	vector <int> hl,wl;
	int h,w,m,a,b;
	map <long long,int> plac;
	bool dec=true;
	cin>>h>>w>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		hn[a]++;
		if(hn[a]==hm){
			hl.push_back(a);
		}else if(hn[a]>hm){
			hl.clear();
			hl.push_back(a);
			hm=hn[a];
		}
		wn[b]++;
		if(wn[b]==wm){
			wl.push_back(b);
		}else if(wn[b]>wm){
			wl.clear();
			wl.push_back(b);
			wm=wn[b];
		}
		plac[a*1000000+b]=1;
	}
	for(int i=0;i<hl.size();i++){
		for(int j=0;j<wl.size();j++){
			if(plac[hl[i]*1000000+wl[j]]!=1){
				dec=false;
				break;
			}
		}
		if(!dec){
			break;
		}
	}
	if(dec){
		cout<<hm+wm-1<<endl;
	}else{
		cout<<hm+wm<<endl;
	}
	return 0;
}
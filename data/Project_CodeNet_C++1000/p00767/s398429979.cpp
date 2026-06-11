#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

bool comp( const pair<int,int> &l, const pair<int,int> &r ){
	int ll = l.first*l.first+l.second*l.second;
	int rr = r.first*r.first+r.second*r.second;
	if( ll == rr ){
		return l.second < r.second;
	}else{
		return ll < rr;
	}
}

int main(){
	vector< pair<int,int> > v;
	for(int h=1; h<150; h++){
		for(int w=h+1; w<150; w++){
			v.push_back( make_pair<int,int>(w,h) );
		}
	}
	sort( v.begin(), v.end(), comp );
	int iw, ih;
	while( cin >> ih >> iw, iw||ih ){
		int l = iw*iw+ih*ih;
		rep(i,v.size()){
			int vl = v[i].first*v[i].first+v[i].second*v[i].second;
			if( (l < vl) ||
				(l==vl && ih<v[i].second) ){
				cout << v[i].second << " " << v[i].first << endl;
				break;
			}
		}
	}
	return 0;
}
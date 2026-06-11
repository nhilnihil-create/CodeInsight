#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <algorithm>

#define rep(i,s,t) for(int i=s;i<t;i++)
#define mp(a,b) make_pair(a,b)
#define mii map<int,int>

using namespace std;

int main(void){
	map<pair<int,int>,int> d;
	rep(h,1,150){
		rep(w,h+1,151){
			d[mp(h*h+w*w,h)]=w;
		}
	}

	int h,w;
	while(true){
		cin >> h >> w;
		if(h==0 && w==0) break;

		map<pair<int,int>,int>::iterator it = d.find(mp(h*h+w*w,h));
		int a_h,a_w;
		it++;
		a_h=(*it).first.second;
		a_w=(*it).second;

		cout << a_h << " " << a_w << endl;

	}
	

	return 0;
}
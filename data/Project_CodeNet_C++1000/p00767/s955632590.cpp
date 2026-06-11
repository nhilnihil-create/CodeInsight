#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

signed main(){
	while(true){
		int H=read(),W=read();
		if(H==0&W==0) break;
		
		int crosslength = H*H+W*W;
		bool flag=false;
		for(int h=H+1;h<150;h++){
			for(int w=1;w<=150;w++){
				if(h>=w) continue;
				if(h*h+w*w == crosslength&&h>H){
					cout << h << ' ' << w << endl;
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		
		if(flag==false){
			int tmpw,tmph;
			int min = 1000000;
			for(int w=1;w<=150;w++){
				for(int h=1;h<w;h++){
					if(h*h+w*w > crosslength&&h*h+w*w<=min){
						min = h*h+w*w;
						tmpw=w;
						tmph=h;
					}
				}
			}
			cout << tmph << ' ' << tmpw << endl;
		}
	}
}
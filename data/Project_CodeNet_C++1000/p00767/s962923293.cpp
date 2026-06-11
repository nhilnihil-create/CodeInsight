
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1186&lang=jp

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

int main() {
	
	int H,W;
	int dia; //Diagonal : 対角線
	pair<int,int> rect; //rectangle : 長方形

	while(cin >> H >> W && H && W)
	{
		dia = H*H + W*W;
		rect.first = 151; rect.second = 151;
		bool found=false;

		int tmpDia=0;
		REP(h,1,151)
		{
			REP(w,h+1,151)
			{
				if(h > H && h != H)
				{
					tmpDia = h*h + w*w;
					if(dia == tmpDia){
						if(h < rect.first){ found=true; rect.first=h; rect.second=w; }
					}
				}
			}
		}

		int nowDia=0;
		if(!found)
		{
			REP(h,1,151)
			{
				REP(w,h+1,151)
				{
					tmpDia = h*h + w*w;
					nowDia = rect.first*rect.first + rect.second*rect.second;
					if(dia < tmpDia && tmpDia < nowDia)
					{
						rect.first = h; rect.second = w;
					}
				}
			}
		}

		cout << rect.first << " " << rect.second << endl;
	}
	
	return 0;
}
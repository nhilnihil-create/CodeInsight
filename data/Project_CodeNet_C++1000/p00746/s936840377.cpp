#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	while(1){
		int N; cin >> N;
		if (N == 0) break;
		if (N == 1){
			cout << 1 << " " <<  1 << endl;
			continue;
		}
		int xmax = 0;
		int xmin = 0;
		int ymax = 0;
		int ymin = 0;
		vector< pair<int,int> > locate(N);
		locate[0] = make_pair(0,0);
		int dx[2][4] = { {-1,0,1,0},
						 {0,-1,0,1} };
		for (int i = 1; i < N; i++){
				int n,d; cin >> n >> d;
				locate[i] = make_pair(locate[n].first + dx[0][d],
										locate[n].second + dx[1][d]);
		}   
		for (int i = 0; i < N; i++){
			if (xmax < locate[i].first) xmax = locate[i].first;  
			if (xmin > locate[i].first) xmin = locate[i].first;  
			if (ymax < locate[i].second) ymax = locate[i].second;  
			if (ymin > locate[i].second) ymin = locate[i].second;  
		}
		cout << xmax - xmin + 1 << " " << ymax - ymin + 1 << endl;	
	}       	
				
return 0;
}
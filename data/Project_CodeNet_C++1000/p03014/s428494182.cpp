#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	
	int h,w; cin>>h>>w;
	vector<string> s(h);
	for(auto &i:s) cin>>i;
	vector<vector<int>> lh(h,vector<int>(w,0)), lw(h,vector<int>(w,0));
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(s.at(i).at(j)!='#'){
				if(j>0&&s.at(i).at(j-1)=='.'){
					lw.at(i).at(j) = lw.at(i).at(j-1);
				}
				else if(s.at(i).at(j)=='.'){
					int x=j; 
					while(1){
						if(x<w&&s.at(i).at(x)=='.') {
							lw.at(i).at(j)++;
						}
						else break;
						x++;
						
					}
				} 
			}
			if(s.at(i).at(j)!='#'){
				if(i>0&&s.at(i-1).at(j)=='.'){
					lh.at(i).at(j) = lh.at(i-1).at(j);
				}
				else if(s.at(i).at(j)=='.'){
					int y=i; 
					while(1){
						if(y<h&&s.at(y).at(j)=='.') {
							lh.at(i).at(j)++;
						}
						else break;
						y++;
					}
				} 
			}
		}
	}
	int msum{};
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(lw.at(i).at(j)==0||lh.at(i).at(j)==0) continue;
			msum = max(msum, lw.at(i).at(j)+lh.at(i).at(j)-1);
		}
	}
	cout << msum << endl;
}

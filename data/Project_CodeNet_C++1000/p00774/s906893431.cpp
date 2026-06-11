#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ban[100][10];;
ll rui[100][10];
ll kazu[6];
ll i,j,h;
ll ans,bans;
string S;
bool solve(){
	cin >> h;
	if(h == 0)return false;
	ans = 0;
	bans = 0;
	h += 5;
	for(i=5;i<h;i++){
		for(j=0;j<5;j++){
			cin >> ban[i][j];
		}
	}
	for(i=h;i<=h+10;i++){
		for(j=0;j<5;j++){
			ban[i][j] = 0;
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			ban[i][j] = 0;
		}
	}
	bool flag = false;
	while(1){
		//cout << "-----" << endl;
		for(i=0;i<h;i++){
			for(j=0;j<5;j++){
				//cout << ban[i][j] << " ";
			}
			//cout << endl;
		}

		//cout << "-----" << endl;
		for(i=h-1;i>=0;i--){
			if(ban[i][0] == ban[i][1] && ban[i][1] == ban[i][2] && ban[i][0] != 0){
				if(ban[i][0] == ban[i][3]){
					if(ban[i][0] == ban[i][4]){
						ans += ban[i][0] + ban[i][1] + ban[i][2] + ban[i][3] + ban[i][4];
						ban[i][0] = 0;
						ban[i][1] = 0;
						ban[i][2] = 0;
						ban[i][3] = 0;
						ban[i][4] = 0;
					}else{

						ans += ban[i][0] + ban[i][1] + ban[i][2] + ban[i][3];
						ban[i][0] = 0;
						ban[i][1] = 0;
						ban[i][2] = 0;
						ban[i][3] = 0;
					}
				}else{
					ans += ban[i][0] + ban[i][1] + ban[i][2];
					ban[i][0] = 0;
					ban[i][1] = 0;
					ban[i][2] = 0;
				}
			}else if(ban[i][1] == ban[i][2] && ban[i][2] == ban[i][3] && ban[i][1] != 0){
				if(ban[i][1] == ban[i][4]){

					ans += ban[i][1] + ban[i][2] + ban[i][3] + ban[i][4];
					ban[i][1] = 0;
					ban[i][2] = 0;
					ban[i][3] = 0;
					ban[i][4] = 0;
				}else{

					ans += ban[i][1] + ban[i][2] + ban[i][3];
					ban[i][1] = 0;
					ban[i][2] = 0;
					ban[i][3] = 0;
				}	
			}else if(ban[i][2] == ban[i][3] && ban[i][3] == ban[i][4] && ban[i][2] != 0){

				ans += ban[i][2] + ban[i][3] + ban[i][4];
				ban[i][2] = 0;
				ban[i][3] = 0;
				ban[i][4] = 0;
			}
		}
		if(bans == ans)break;
		for(int num = 0; num <= 15; num ++){
		for(i=h-1;i>=1;i--){
			for(j=0;j<5;j++){
				if(ban[i][j] == 0){
					swap(ban[i][j],ban[i-1][j]);
				}
			}
		}}
		bans = ans;
	}
	cout << ans << endl;
	return true;
}

int main(){
	while(solve()){}
	return 0;
}

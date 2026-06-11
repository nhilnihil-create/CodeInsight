#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> bingo(9);
	for(int i=0;i<9;i++) cin >> bingo[i];
	int n;
	cin >> n;
	vector<int> flag(9,0); 
	for(int i=0;i<n;i++){
		int b;
		cin >> b;
		auto itr = find(bingo.begin(),bingo.end(),b);
		if(itr != bingo.end()){
			int index = distance(bingo.begin(),itr);
			flag.at(index) = 1;
		}
	}
	if((flag[0] && flag[1] && flag[2]) || (flag[3] && flag[4] && flag[5]) || (flag[6]&& flag[7] && flag[8]) || (flag[0] && flag[3] && flag[6]) || (flag[1] && flag[4] &&flag[7])||(flag[2] && flag[5] && flag[8])||(flag[0]&&flag[4]&&flag[8])||(flag[2]&&flag[4]&&flag[6])){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}

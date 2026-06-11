#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<bool> ac_flg(n,false);
	vector<int> count_pen(n, 0);
	
	int ac = 0, pen = 0;
	
	for(int i = 0; i < m; i++){
		int prob_num;
		string result = (char*)calloc(3, sizeof(char));
		cin >> prob_num >> result;
		
		if(!ac_flg.at(prob_num-1)){//一度もACしてない
			if(result == "AC"){
				ac++;
				ac_flg.at(prob_num-1) = true;
			}
			else{
				count_pen.at(prob_num-1)++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(ac_flg.at(i)) pen += count_pen.at(i);
	}
	
	cout << ac << " " << pen << endl;
	
}
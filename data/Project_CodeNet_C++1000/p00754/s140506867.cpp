#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	string sentence;
	bool flag;
	string answer;
	vector<int> kakko; //1: mkakkko 2: kkakkko
	int leng = -1;


	while(1){
		answer = "yes";
		getline(cin,sentence);

		if(sentence == "."){
			break;
		}
		for(int i = 0 ; i < leng+1;i++){
			kakko.pop_back();
		}
		leng = -1;

		for(int i = 0; i < sentence.length();i++){
			if(sentence[i] == '('){
				kakko.push_back(1);
				leng++;
				//cout << " testcase 1 " << endl;
			}else if(sentence[i] == '['){
				kakko.push_back(2);
				leng++;
				//cout << " testcase 2" << endl;
			}else if(sentence[i] == ')'){
				if(leng == -1){
					answer = "no";
					break;
				}else{
					if(kakko[leng] == 1){
						kakko.pop_back();
						leng--;
					}else{
						answer = "no";
						break;
					}
				}
				//cout << " testcase 3" << endl;
			}else if(sentence[i] == ']'){
				if(leng == -1){
					answer = "no";
					break;
				}else{
					if(kakko[leng] == 2){
						kakko.pop_back();
						leng--;
					}else{
						answer = "no";
						break;
					}
				}
				//cout << " testcase 4" << endl;

			}else{}
		}
		if(leng > -1){
			answer = "no";
		}
			
		cout << answer << endl;

	}

}
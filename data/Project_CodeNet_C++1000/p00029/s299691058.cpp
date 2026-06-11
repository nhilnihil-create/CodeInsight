#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int main(){

	std::string str;
	std::getline(std::cin, str);

	std::vector<std::string> moji;
	std::vector<int> cost;

	std::string maxsize = "A";

	for (int i = 0, j = 0; i <= str.size(); i++){
		if (i == str.size() - 1 || str[i] == ' '){
			std::string s = str.substr(j, i - j);
			j = i + 1;

			std::vector<std::string>::iterator it = std::find(moji.begin(), moji.end(), s);
			if (it == moji.end()){
				moji.push_back(s);
				cost.push_back(1);
			}
			else {
				cost[it - moji.begin()]++;
			}

			if (s.size() > maxsize.size())maxsize = s;
		}
	}

	
	int maxhind = 0;
	std::string res;
	for (int i = 0; i < moji.size(); i++){
		if (cost[i]>maxhind){
			res = moji[i];
			maxhind = cost[i];
		}
	}

	std::cout << res << " " << maxsize << std::endl;

	return 0;
}
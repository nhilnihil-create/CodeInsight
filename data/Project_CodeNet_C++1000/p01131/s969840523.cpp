#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <queue>

#pragma warning( disable: 4996 )

using namespace std;

typedef long long ll;

#define INF 1000000000
#define EPS 1e-10

string str;

string S[10];

vector<string> ans_list;

int main(){

	S[1] = ".,!? ";
	S[2] = "abc";
	S[3] = "def";
	S[4] = "ghi";
	S[5] = "jkl";
	S[6] = "mno";
	S[7] = "pqrs";
	S[8] = "tuv";
	S[9] = "wxyz";

	int N;
	cin >> N;

	while (N > 0){

		N--;
		cin >> str;

		int num = 0;
		int end = 0;
		char tmp[2];
		tmp[1] = '\0';
		string ans;

		while (true){
			if (str[num] == '0'){
				num++;
				if (str.length() == num)
					break;
			}

			else{
				tmp[0] = str[num];
				bool flag = false;
				for (int i = num; i < str.length(); i++){
					if (str[i] == '0'){
						end = i;
						flag = true;
						break;
					}
				}
				if (!flag)
					break;
				int count = end - num;
				count--;
				int n = S[atoi(tmp)].length();
				ans += S[atoi(tmp)][count%n];
				num = end;
			}

		}

		ans_list.push_back(ans);

	}

	for (int i = 0; i < ans_list.size(); i++){
		cout << ans_list[i] << endl;
	}

	return 0;

}
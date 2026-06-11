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

string k[3];
int f[1000000];

vector<string> ans_list;

int main(){

	k[0] = "()";
	k[1] = "[]";

	while (true){
		getline(cin, str);
		if (str == ".")
			break;

		int num;
		int f_c = -1;

		for (num = 0; num < str.length(); num++){
			if (k[0][0] == str[num]){
				f_c++;
				f[f_c] = 0;
			}
			else if (k[1][0] == str[num]){
				f_c++;
				f[f_c] = 1;
			}
			else if (k[0][1] == str[num]){
				if (f_c < 0 || f[f_c] != 0)
					break;
				f_c--;
			}
			else if (k[1][1] == str[num]){
				if (f_c < 0 || f[f_c] != 1)
					break;
				f_c--;
			}
		}

		if (num == str.length() && f_c < 0)
			ans_list.push_back("yes");
		else
			ans_list.push_back("no");


	}

	for (int i = 0; i < ans_list.size(); i++){
		cout << ans_list[i] << endl;
	}

	return 0;

}
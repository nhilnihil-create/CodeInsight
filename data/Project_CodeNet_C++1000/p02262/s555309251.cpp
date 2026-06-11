#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>

using namespace std;
string shell_sort(string, int, int, vector<int>, int&);
int* insert_sort_4_shell(int*, int, int, int&);
string intArrayToString(int*, int);

int main()
{
	string str;
	getline(cin, str);
	int num;
	stringstream num_ss(str);
	num_ss >> num;
	str = "";
	string buff;
	for (int i = 0; i < num; i++) {
		getline(cin, buff);
		if (i == num - 1) {
			str += buff;
		} else {
			str += buff + " ";
		}
	}
	int counter = 0;
	int m = 0;
	vector<int> G;
	while (pow(2, m+1) -1 <= num) {
		G.insert(G.begin(), pow(2, m+1) - 1);
		m++;
	}
	str = shell_sort(str, num, m, G, counter);
	cout << m << endl;
	string G_str = "";
	for (int i = 0; i < G.size(); i++) {
		if (i == G.size() - 1) {
			G_str += to_string(G[i]);
		}
		else {
			G_str += to_string(G[i]) + " ";
		}
	}
	cout << G_str << endl;
	cout << counter << endl;
	stringstream ans(str);
	while (getline(ans, buff, ' ')) {
		cout << buff << endl;
	}

	return 0;
}

string shell_sort(string str, int ary_size, int m, vector<int> G, int &counter) {
	int* ary = new int[ary_size];
	stringstream ss(str);
	string buff;
	int cnt = 0;
	while (getline(ss, buff, ' ')) {
		stringstream tss(buff);
		tss >> ary[cnt];
		cnt++;
	}

	// main.
	for (int i = 0; i < m; i++) {
		insert_sort_4_shell(ary, ary_size, G[i], counter);
	}

	return intArrayToString(ary, ary_size);
}

int* insert_sort_4_shell(int* ary, int ary_size, int g, int &counter) {

	// main.
	for (int i = g; i < ary_size; i++) {
		int v = ary[i];
		for (int j = i - g; j >= 0 && v < ary[j]; j -= g) {
			ary[j + g] = ary[j];
			ary[j] = v;
			counter++;
		}
	}

	return ary;
}

string intArrayToString(int* ary, int ary_size) {
	string str = "";
	for (int i = 0; i < ary_size; i++) {
		if (i == ary_size - 1) {
			str += to_string(ary[i]);
		}
		else {
			str += to_string(ary[i]) + " ";
		}
	}
	return str;
}
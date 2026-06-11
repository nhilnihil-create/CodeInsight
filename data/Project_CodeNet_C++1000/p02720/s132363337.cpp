#include <bits/stdc++.h>

using namespace std;

int ctoi(char a)
{
	return a-'0';
}
int itoc(int n)
{
	return '0'+n;
}

int main(void)
{
	int k;
	cin >> k;
	string s = "1";
	int count = 0;
	for (int i = 1; i < k; i++) {
		/*
		for (int j = s.size()-1; j >= 0; j--) {
			if (j == 0) {
				if (ctoi(s[j])+1 == 10) {
					s[j] = '0';
					s.insert(s.begin(), '1');
				} else {
					s[j] = itoc(ctoi(s[j]) + 1);
				}
			} else {
			*/
		if (s.size() == 1) {
			if (ctoi(s.back()+1)== 10) {
				s[0] = '0';
				s.insert(s.begin(), '1');
			} else {
				s[0] = itoc(ctoi(s[0])+1);
			}
		} else if (s.size() >= 2) {
			if (ctoi(s.back())+1 == 10 || abs(ctoi(s.back())+1 - ctoi(s[s.size()-2])) >= 2) {
				int k;
				for (k = s.size()-1; k > 0; k--) {
					if (abs(ctoi(s[k])+1 -ctoi(s[k-1]))<= 1 && ctoi(s[k])+1 <= 9) {
						break;
					}
				}

				bool add = false;
				if (ctoi(s[k])+1 == 10 && k== 0)
					add = true;
				s[k] = itoc((ctoi(s[k])+1)%10);
				for (int j = k+1; j < s.size(); j++) {
					s[j] = itoc(max(ctoi(s[j-1])-1, 0));
				}
				if (add)
					s.insert(s.begin(), '1');
			} else {
				s[s.size()-1] = itoc(ctoi(s.back())+1);
			}

		}
		//cout << s << endl;
	}
	cout << s << endl;
	return 0;
}
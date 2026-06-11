#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
//#include<cmath>
using namespace std;

typedef struct {
	string s;
	int t;
}Unit;

int main(void)
{
	int n, m;
	cin >> n;
	list<int> L;
	char s[20];
	for (int i = 0; i < n; i++) {
		scanf("%s %d", s, &m);
		if (s[0] == 'i') {
			L.push_front(m);
		}
		else if (strlen(s) == 6) {
			for (list<int>::iterator it=L.begin(); it != L.end(); it++) {
				if (*it == m) {
					L.erase(it);
					break;
				}
			}
		}
		else if (strlen(s) == 11) {
			L.pop_front();
		}
		else {
			L.pop_back();
		}
	}
	int i = 0;
	for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
		if (i++)
			cout << " ";
		cout << *it;
	}
	cout << endl;
	return 0;
}

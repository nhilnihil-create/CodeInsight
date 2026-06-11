#include <iostream>
#include <vector>

#define _GLIBCXX_DEBUG

using namespace std;
int main() {
	int n = 0,c=0,d=0,f=0;
	bool flag=false;
	
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);

	for (int i = 0; i < n; i++) {
		cin >> a.at(i) >>b.at(i);
	}
	
	for (int i = 0; i < n; i++) {
		if (a.at(i)==b.at(i)) {
			f++;
			if (f == 3)
				flag = true;
		}
		else
			f = 0;
		c = a.at(i);
		d = b.at(i);
	}

	if (flag == true)
		cout << "Yes";
	else
		cout << "No";
}
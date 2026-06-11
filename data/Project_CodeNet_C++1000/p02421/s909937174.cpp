
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	string str1, str2;
	int i,n,taro=0,hanako=0,j=0,a,b,c;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> str1;
		cin >> str2;
		b = str1.length();
		c = str2.length();
		a = min(b, c);
		for (j = 0; j < a; j++) {
			if (int(str1[j]) > int(str2[j])) {
				taro += 3;
				break;
			}
			else if (int(str1[j]) < int(str2[j])) {
				hanako += 3;
				break;
			}
			if (j == (a - 1)) {
				if (str1 == str2) {
					taro += 1;
					hanako += 1;
				}
				else if (str1.length() > str2.length()) {
					taro += 3;
				}
				else if (str1.length() < str2.length()) {
					hanako += 3;
				}
			}
		}
	}
		
	cout << taro << " " << hanako<<endl;
}


#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<iomanip>
#include<list>
#include<math.h>
#include<stack>

using namespace std;

int n = 0;
int s = 0;
static int ans;

void check(int atai, int num, int count){
	if (num > 9) {
		if (atai == s && count == n) {
			ans++;
		}
		return;
	}
	check(atai + num, num + 1, count + 1);
	check(atai, num + 1, count);
}


int main(int argc, char **argv)
{
	while (cin >> n >> s) {
		ans = 0;
		if (n == 0 && s == 0) {
			break;
		}
		check(0, 0, 0);
		cout << ans << endl;
	}
}
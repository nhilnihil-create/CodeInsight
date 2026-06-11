#include <bits/stdc++.h>

int main(void)
{
	int A, B, C;
	std::cin >> A >> B >> C;

	bool flag = false;

	if (A == B) {
		if (B != C) {
			flag = true;
		}
	}
	else {
		if (B == C) {
			flag = true;
		}
		else if (A == C) {
			flag = true;
		}
	}

	if (flag)
		std::cout << "Yes" << std::endl;
	else 
		std::cout << "No" << std::endl;
}
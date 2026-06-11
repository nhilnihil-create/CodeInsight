#include <iostream>
#include <string>
#include <list>
#include <algorithm>

int main() {

	std::cin.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	std::list<int> l;

	for (int i = 0; i < n; i++) {
		std::string op;
		int x;
		std::cin >> op;
		if(op == "insert" || op == "delete")
			std::cin >> x;
			
		if (op == "insert")
			l.push_front(x);
		else if (op == "deleteFirst")
			l.pop_front();
		else if (op == "deleteLast")
			l.pop_back();
		else if (op == "delete") {
			std::list<int>::iterator i = std::find(l.begin(), l.end(),x);
			if( i != l.end())
				l.erase(i);
		}
	}

	for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i) {
		if (++i != l.end())
			std::cout << *(--i) << " ";
		else
			std::cout << *(--i) << std::endl;
	}


	return 0;
}
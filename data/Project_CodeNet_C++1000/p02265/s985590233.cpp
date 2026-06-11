#include<iostream>
#include<string>
#include<list>
int main() {
	int n, i, x;
	std::cin >> n;
	std::string command;
	std::list<int> l;
	for (i = 0; i < n; i++) {
		std::cin >> command;
		if (command == "insert") {
			std::cin >> x;
			l.push_front(x);
		}
		else if (command == "delete") {
			std::cin >> x;
			for (std::list<int>::iterator itr = l.begin(); itr != l.end(); ++itr) {
				if (*itr == x) {
					l.erase(itr);
					break;
				}
			}
		}
		else if (command == "deleteFirst") {
			l.pop_front();
		}
		else if (command == "deleteLast") {
			l.pop_back();
		}
	}
	for (std::list<int>::iterator itr = l.begin(); itr != l.end(); ++itr) {
		if (itr != l.begin())std::cout << " ";
		std::cout << *itr;
	}
	std::cout << "\n";
	return 0;
}

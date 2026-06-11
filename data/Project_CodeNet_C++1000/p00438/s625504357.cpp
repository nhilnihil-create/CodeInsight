#include <iostream>
#include <vector>

class Search {
	int a,b;
	//int n;
	std::vector<std::vector<bool>> searched_point;

public:
	int count;
	void set_searched_point(int n_a, int n_b);
	void prohibit(int n);
	bool pass_search(int x,int y);

};

void Search::set_searched_point(int n_a, int n_b) {

	a = n_a;
	b = n_b;
	count = 0;

	searched_point.resize(a + 1);

	for (int i = 0; i < a + 1; ++i) {
		searched_point[i].resize(b + 1);
	}

	for (int i = 0; i < a + 1; ++i){
		for (int j = 0; j < b+1; ++j){
			searched_point[i][j] = false;
		}
	}

	return;
}

void Search::prohibit(int n) {

	int p_x, p_y;//prohibit point

	for (int i = 0; i < n; ++i){
		std::cin >> p_x >> p_y;
		searched_point[p_x][p_y] = true;
	}

	return;
}

bool Search::pass_search(int x,int y) {

	if (searched_point[x][y] == true) {
		return true;
	}
	else if (x == a && y == b) {
		++count;
		return true;
	}
	else if (x == a) {
		pass_search(x, y + 1);
	}
	else if (y == b) {
		pass_search(x + 1, y);
	}
	else {
		pass_search(x + 1, y);
		pass_search(x, y + 1);
	}

}

int main() {

	int a,b;
	int n;
	Search se;

	while (true){

		std::cin >> a >> b;

		if (a == 0 && b == 0){
			break;
		}
		else {
			se.set_searched_point(a, b);
		}

		std::cin >> n;

		se.prohibit(n);
		se.pass_search(1, 1);

		std::cout << se.count << std::endl;
	}

	return 0;
}
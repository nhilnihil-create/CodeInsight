#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Water {
public:
	int size;
	int position;
	Water(int _size, int _position) {
		size = _size;
		position = _position;
	}
	void fill(int addition) {
		size += addition;
	}
	void merge(Water* water) {
		if (water) {
			size += water->size;
			delete water;
		}
	}
};

// it returns false if no action is committed
bool mergeWaters(int position, vector<Water*>& waters) {
	Water* accum = NULL;
	Water* water;
	while (! waters.empty() && (water = waters.back())->position >= position) {
		waters.pop_back();
		water->merge(accum);
		accum = water;
	}
	if (accum) {
		waters.push_back(accum);
		return true;
	} else {
		return false;
	}
}

int main() {
	string pattern;
	vector<Water*> waters;
	stack<int> positions;
	int total = 0;
	
	cin >> pattern;
	
	for (int pos = 0, len = pattern.length(); pos < len; pos++) {
		switch (pattern[pos]) {
		case '\\':
			positions.push(pos);
			break;
		case '/':
			if (! positions.empty()) {
				int top = positions.top(); positions.pop();
				int addition = pos - top;
				if (mergeWaters(top, waters))
					waters.back()->fill(addition);
				else
					waters.push_back(new Water(addition, top));
				total += addition;
			}
			break;
		case '_':
			break;
		}
	}
	
	cout << total << endl;
	cout << waters.size();
	for (Water* water : waters) {
		cout << ' ' << water->size;
	}
	cout << endl;
}
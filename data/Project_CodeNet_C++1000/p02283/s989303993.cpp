#include<iostream>
#include<string>

struct tree {
	int node;
	tree *right;
	tree *left;
};

void insert(tree *trees) {
	int num;
	std::cin >> num;
	tree *t = new tree;
	t->node = num;
	t->left = NULL;
	t->right = NULL;
	while (true) {
		if (trees->node > num) {
			if (trees->left != NULL) {
				trees = trees->left;
			} else {
				trees->left = t;
				return;
			}
		} else {
			if (trees->right != NULL) {
				trees = trees->right;
			} else {
				trees->right = t;
				return;
			}
		}
	}
}

void show_in_order(tree *trees) {
	if (trees->left != NULL) show_in_order(trees->left);
	std::cout << " " << trees->node;
	if (trees->right != NULL) show_in_order(trees->right);
}

void show_pre_order(tree *trees) {
	std::cout << " " << trees->node;
	if (trees->left != NULL) show_pre_order(trees->left);
	if (trees->right != NULL) show_pre_order(trees->right);
}

void solve(tree *trees) {
	int num;
	std::cin >> num;
	std::string str;
	std::cin >> str;
	int n;
	std::cin >> n;
	trees->node = n;
	trees->left = NULL; trees->right = NULL;

	for (int i = 0; i < num - 1; i++) {
		std::cin >> str;
		if (str == "insert") {
			insert(trees);
		} else if (str == "print") {
			show_in_order(trees);
			std::cout << std::endl;
			show_pre_order(trees);
			std::cout << std::endl;
		}
	}
}

int main() {
	tree trees;
	solve(&trees);

	return 0;
}
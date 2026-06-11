#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int InsertionSort(int *array, int size, int span);
string JoinWith(int *array, int size, const char *joiner);

int main() {
	int n;
	cin >> n;

	int array[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	// Start shell sort.
	stack<int> span_stack;
	for (int i = 1; i < n; i = 3 * i + 1) {
		span_stack.push(i);
	}
	if (span_stack.empty()) {
		span_stack.push(1);
	}

	int times_of_inssort = span_stack.size();
	int spans[times_of_inssort];
	int index = 0;
	int count = 0;
	while(!span_stack.empty()) {
		int span = span_stack.top();
		span_stack.pop();
		count += InsertionSort(array, n, span);
		spans[index++] = span;
	}

	cout << times_of_inssort << endl;
	cout << JoinWith(spans, times_of_inssort, " ") << endl;
	cout << count << endl;
	cout << JoinWith(array, n, "\n") << endl;
	return 0;
}

int InsertionSort(int *array, int size, int span) {
	int count = 0;
	for (int i = span; i < size; i++) {
		int current = array[i];
		int j = i - span;
		while (j >= 0 && array[j] > current) {
			array[j + span] = array[j];
			j -= span;
			count++;
		}
		array[j + span] = current;
	}
	return count;
}

string JoinWith(int *array, int size, const char *joiner) {
	ostringstream oss;
	for (int i = 0; i < size - 1; i++) {
		oss << array[i] << joiner;
	}
	oss << array[size - 1];
	return oss.str();
}
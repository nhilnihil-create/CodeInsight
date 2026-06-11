#include<iostream>

using namespace std;

struct process {
	char name[20];
	int time;
	int consume;
};

int head, tail, MAX;
process queue[100000];

void initialize(int max) {
	MAX = max + 1;

	head = 0;
	tail = 0;
}

void enqueue(process p) {
	queue[tail] = p;
	tail += 1;
	if (tail == MAX) {
		tail = 0;
	}
}

process dequeue() {
	process p = queue[head];
	head += 1;
	if (head == MAX) {
		head = 0;
	}
	return p;
}

bool isEmpty() {
	return head == tail;
}

int main() {
	int n, q;

	cin >> n;
	cin >> q;

	initialize(n);

	for (int i = 0; i < n; i++) {
		process tmp;
		cin >> tmp.name; 
		cin >> tmp.time; 
		enqueue(tmp);
	}
	
	int consumed = 0;

	while (!isEmpty()) {
		process p = dequeue();
		
		if (p.time <= q) {
			consumed += p.time;
			cout << p.name << " " << consumed << endl;
		} else {
			consumed += q;
			p.time -= q;
			enqueue(p);
		}
	}
}
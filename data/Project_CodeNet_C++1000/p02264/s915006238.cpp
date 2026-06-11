#include <iostream>

typedef struct {
	int time;
	char name[10];
} process;

const int q_size = 100000;
process queues[q_size];

using namespace std;

int head = 0;
int tail = 0;

bool isEmpty()
{
	if (head == tail)
		return true;
	return false;
}

bool isFull()
{
	if (head == ((tail + 1) % q_size))
		return true;
	return false;
}

void Enqueue(process p)
{
	if (isFull()) {
		cout << "Queues is full." << endl;
		//exit(EXIT_FAILURE);
	}
	if (tail == q_size)
		tail = 0;
	queues[tail++] = p;
}

process Dequeue()
{
	if (isEmpty()) {
		cout << "No process." << endl;
		//exit(EXIT_FAILURE);
	}
	if (head + 1 == q_size) {
		process p = queues[head];
		head = 0;
		return p;
	}
		
	return queues[head++];
}

int main(void)
{
	int n, q;
	process p;

	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> p.name >> p.time;
		Enqueue(p);
	}
	int time = 0;
	while (n > 0) {
		p = Dequeue();
		if (p.time - q > 0) {
			p.time -= q;
			Enqueue(p);
			time += q;
		}
		else {
			time += p.time;
			cout << p.name << " " << time << endl;
			n--;
		}
	}

	return 0;
}
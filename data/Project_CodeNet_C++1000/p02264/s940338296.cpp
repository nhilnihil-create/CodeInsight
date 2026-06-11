#include <cstdio>
#include <cstring>
#define LEN 100005

/* queue struction */
unsigned int time[LEN], head, tail;
char name[LEN][10];

int main()
{
	int n, runtime;
	head = tail = 0;

	scanf("%d %d", &n, &runtime);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", name[i], &time[i]);
		tail++; // always point to empty
	}

	int timer = 0; // timer
	while (tail != head) { // Not empty <- Important, different between "tail != head" and "tail - head > 0"
		// Process - not finished
		if (time[head % LEN] > runtime) {
			timer += runtime;
			strcpy(name[(tail) % LEN], name[(head) % LEN]); // str copy
			time[(tail) % LEN] = time[(head) % LEN] -= runtime;
			tail++, head++;
		}
		else {
			timer += time[(head) % LEN];
			printf("%s %d\n", name[(head) % LEN], timer);
			head++;
		}
	}

	return 0;
}
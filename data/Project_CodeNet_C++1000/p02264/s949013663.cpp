#include<stdio.h>
#include<string.h>
#define LENGTH 100005 // プロセスの制約 100000 のため

// 構造体
// Process という別名をつけている
typedef struct pp {
	char name[100];
	int time;
} Process;

Process Queue[LENGTH]; // Process structの配列
int head, tail, countOfProcess; // head ... 先頭ポインタ, tail ... 末尾ポインタ

void enqueue(Process process)
{
	Queue[tail] = process;
	tail = (tail + 1) % LENGTH;
}

Process dequeue()
{
	Process process = Queue[head];
	head = (head + 1) % LENGTH;
	return process;
}

int min(int a, int b ) { return a < b ? a : b; }

int main()
{
	// 変数は、使用する前に宣言しなければならない。
	// C言語では宣言はプログラムの冒頭でなければならなかったが、 C言語を拡張した C++ ではプログラムのどこでも宣言できる。
	int totalTime = 0, consumption;
	int i, quantum;
	Process process;
	scanf("%d %d", &countOfProcess, &quantum);

	for ( i = 1; i <= countOfProcess; i++)
	{
		scanf("%s", Queue[i].name);
		scanf("%d", &Queue[i].time);
	}
	head = 1; tail = countOfProcess + 1;

	while(head != tail){
		process = dequeue();
		consumption = min(quantum, process.time);
		process.time -= consumption;
		totalTime += consumption;
		if(process.time > 0){
			enqueue(process);
		}else{
			printf("%s %d\n", process.name, totalTime);
		}
	}
	return 0;
}

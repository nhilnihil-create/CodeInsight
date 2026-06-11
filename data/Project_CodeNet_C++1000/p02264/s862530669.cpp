#include <iostream>
#include <string>


using namespace std;

const int con = 100002;

struct process
{
	string name;
	int time;
};

class queue
{
public:
	process q[con];
	int tail,head;
	void initialize();
	void enqueue(process x);
	process dequeue();
};

void queue::initialize()
{
	head = tail = 0;
}

void queue::enqueue(process x)
{
	q[tail] = x;
	if (tail+1 == con)
	{
		tail = 0;
	}else
	{
		tail++;
	}
}

process queue::dequeue()
{
	process x;
	x = q[head];

	if (head+1 == con)
	{
		head = 0;
	}else
	{
		head++;
	}

	return x;
}



int main()
{
	int n, q, nowtime, j = 0;
	process p[100000], result[100000], temp;
	queue que;

	que.initialize();

	cin >> n >> q;

	for(int i = 0; i < n; i++)
	{
		cin >> p[i].name >> p[i].time;
		que.enqueue(p[i]);
	}

	while(que.tail != que.head)
	{
		temp = que.dequeue();

		if (temp.time - q <= 0)
		{
			nowtime += temp.time;

			/*result[j].name = temp.name;
			result[j].time = nowtime;
			j++;
			*/

			cout << temp.name << " " << nowtime << "\n";

		}else
		{
			temp.time -= q;
			nowtime += q;
			que.enqueue(temp);
		}

	}

	/*for(int i = 0; i < n; i++)
	{
		cout << result[i].name << " " << result[i].time <<"\n";
	}*/


	return 0;
}
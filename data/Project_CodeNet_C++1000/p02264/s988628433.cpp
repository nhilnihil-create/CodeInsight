#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct process
{
	string name;
	int    time;
};

struct finished
{
	string name;
	int    time;
};

queue<finished> RoundRobin(queue<process> X, int q)
{
	queue<finished> Y;
	int totaltime = 0;
	while(X.size() > 0){
		if(X.front().time <= q){
			totaltime += X.front().time;
			finished output;
			output.name = X.front().name;
			output.time = totaltime;
			X.pop();
			Y.push(output);
		}else{
			totaltime += q;
			X.front().time -= q;
			X.push(X.front());
			X.pop();
		}
	}
	return Y;
}

int main()
{
	int n, q;
	cin >> n;
	cin >> q;
	queue<process> Input;
	for(int i = 0; i < n; i++){
		process imput;
		cin >> imput.name >> imput.time;
		Input.push(imput);
	}
	queue<finished> Output = RoundRobin(Input, q);
	for(int i = 0; i < n; i++){
		cout << Output.front().name << " " << Output.front().time << endl;
		Output.pop();
	}
	return 0;
}
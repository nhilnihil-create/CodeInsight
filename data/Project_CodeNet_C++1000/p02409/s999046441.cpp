#include<iostream>
using namespace std;

#define B_MAX 4
#define F_MAX 3
#define R_MAX 10 

class Ans
{
public:
	Ans()
	{
		for(int i = 0; i < F_MAX; i++)
		{
			for(int j = 0; j < R_MAX; j++)
			{
 				data[i][j] = 0;
 			}
 		}	
 	}
 	
 	int data[F_MAX][R_MAX];

	void Input(int f, int r, int v);
	void Output();
};

void Ans::Input(int f, int r, int v)
{
	data[f][r] += v;
	return ;
}
void Ans::Output()
{
	for(int i = 0; i < F_MAX; i++)
 	{
 		for(int j = 0; j < R_MAX; j++)
 		{
 			cout << " " << data[i][j];
 		}
 		cout << endl;
	}
 	return ;
}
 
class Answer
{
public:
	Answer(){}
 	Ans ans[B_MAX];
 	int b, f, r, v;
 	
 	void Input();
 	void Output();		
};
 
void Answer::Input()
{	
	cin >> b >> f >> r >> v;
	ans[b - 1].Input(f - 1, r - 1, v);	
}
void Answer::Output()
{
	for(int i = 0; i < B_MAX; i++)
	{
		ans[i].Output();
		
		if( i == (B_MAX - 1) )break;
		
		for(int j = 0; j < 20; j++)
			cout << "#";
		cout << endl;
	}
}

int main()
{
	Answer ans;
	int N;
	
	cin >> N;
	for(int i = 0; i < N; i++)
		ans.Input();
	ans.Output();
	
	return 0;
}
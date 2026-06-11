#include <iostream>
#include <vector>

int BALLNUM = 10;

	static int data[10];
class balldata
{
private:
	//static std::vector <int> data;
	//int ballnum;
public:
	balldata(int datanum);
	static void enter();
	static void answer();
	static bool check();
	static bool check(int num,int right,int left);
};




int main()
{
	balldata ball(BALLNUM);

int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		ball.enter();
		ball.answer();
	}
}


balldata::balldata(int datanum)
{
	//ballnum = datanum;
	//data.resize(datanum);
}



void balldata::enter()
{
	for (int i = 0; i < 10; i++)
	{
		std::cin >> data[i];
	}
	return;
}

bool balldata::check(int num,int right,int left)
{
	//if (num == data.size())return true;
	if (num == 10)return true;
	if (balldata::check(num + 1, right, data[num])&&left<data[num]){ return true; }
	if (balldata::check(num + 1, data[num], left)&&right<data[num]){ return true; }

	return false;
}
bool check()
{
	return balldata::check(0, 0, 0);
}

void balldata::answer()
{ 
	if (balldata::check(0, 0, 0))
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
}
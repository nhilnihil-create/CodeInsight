#include<iostream>
#include<string>


#define INPUT_MAX 101
#define KAKKO_MAX 49

using namespace std;

int main(void)
{
	int countMaru = 0;
	int countKaku = 0;
	int idx = 0;
	string stack(KAKKO_MAX, '\0');
	string dataset(INPUT_MAX, '\0');
	
	while(getline( cin, dataset))
	{
		if(dataset[0] == '.')
		{
			break;
		}
		for(int i = 0; i < INPUT_MAX; i++)
		{
			if(dataset[i] == '.')
			{
				if((countMaru == 0) && (countKaku == 0))
				{
					cout << "yes\n";
					break;
				}
				else
				{
					cout << "no\n";
					break;
				}
			}
			else if(dataset[i] == '(')
			{
				if(idx == KAKKO_MAX)
				{
					cout << "no\n";
					break;
				}
				countMaru++;
				stack[idx] = '(';
				idx++;
			}
			else if(dataset[i] == '[')
			{
				if(idx == KAKKO_MAX)
				{
					cout << "no\n";
					break;
				}
				countKaku++;
				stack[idx] = '[';
				idx++;
			}
			else if(dataset[i] == ')')
			{
				if(idx == 0)
				{
					cout << "no\n";
					break;
				}
				else if(stack[idx-1] == '[')
				{
					cout << "no\n";
					break;
				}
				else
				{
					idx--;
					stack[idx] = '\0';
					countMaru--;
				}
			}
			else if(dataset[i] == ']')
			{
				if(idx == 0)
				{
					cout << "no\n";
					break;
				}
				else if(stack[idx-1] == '(')
				{
					cout << "no\n";
					break;
				}
				else
				{
					idx--;
					stack[idx] = '\0';
					countKaku--;
				}
			}
			else
			{
				// 処理なし
			}
		}
		
		idx = 0;
		countMaru = 0;
		countKaku = 0;
	}
	
	return 0;
}



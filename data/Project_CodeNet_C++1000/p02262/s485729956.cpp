#include <algorithm>
#include <iostream>
#include <vector>

void InputNumbers(int& Count,std::vector<int>& Numbers);
void OutputNumbers(const std::vector<int>& Numbers);
void InsertionSort(std::vector<int>& Numbers,const int Interval,int& InsertCount);
int ShellSort(std::vector<int>& Numbers, const std::vector<int>& Intervals);
void CreateIntervals(std::vector<int>& Intervals,const int Count);

int main()
{
	int Count = 0;
	std::vector<int> Numbers;
	InputNumbers(Count,Numbers);
	
	std::vector<int> Intervals;
	CreateIntervals(Intervals,Count);
	
	std::cout << Intervals.size() << std::endl;
	OutputNumbers(Intervals);
	
	int InsertCount = ShellSort(Numbers,Intervals);
	
	std::cout << InsertCount << std::endl;
	
	for(unsigned int i=0;i<Numbers.size();i++)
	{
		std::cout << Numbers[i] << std::endl;
	}
	
	return 0;
}

void InputNumbers(int& Count,std::vector<int>& Numbers)
{
	std::cin >> Count;
	for(int i=0;i<Count;i++)
	{
		int Input = 0;
		std::cin >> Input;
		Numbers.push_back(Input);
	}
}

void OutputNumbers(const std::vector<int>& Numbers)
{
	for(unsigned int i=0;i<Numbers.size();i++)
	{
		std::cout << Numbers[i] << std::flush;
		if(i != Numbers.size() - 1)
		{
			std::cout << " " << std::flush;
		}else{
			std::cout << std::endl;
		}
	}
}


void InsertionSort(std::vector<int>& Numbers,const int Interval,int& InsertCount)
{
	for(unsigned int i = Interval;i<Numbers.size();i++)
	{
		int v = Numbers[i];
		int j = i - Interval;
		while(j >= 0 && Numbers[j] > v)
		{
			Numbers[j+Interval] = Numbers[j];
			j -= Interval;
			InsertCount++;
		}
		Numbers[j+Interval] = v;
	}
}

int ShellSort(std::vector<int>& Numbers, const std::vector<int>& Intervals)
{
	int InsertCount = 0;
	for(unsigned int i = 0;i<Intervals.size();i++)
	{
		InsertionSort(Numbers,Intervals[i],InsertCount);
	}
	return InsertCount;
}

void CreateIntervals(std::vector<int>& Intervals,const int Count)
{
	int h = 1;
	while(h<Count || h==1)
	{
		Intervals.push_back(h);
		h = 3*h + 1;
	}
	std::reverse(Intervals.begin(),Intervals.end());
}
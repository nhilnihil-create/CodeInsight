#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nCnt=0;

void insertionSort(int nIn[],int nNum,int nG)
{
	int nMin=0;
	int j=0;
	for(int i=nG;i<=nNum-1;++i)
	{
		nMin=nIn[i];
		j=i-nG;
		while(j>=0 && nIn[j]>nMin)
		{
			nIn[j+nG]=nIn[j];
			j-=nG;
			nCnt++;
		}
		nIn[j+nG]=nMin;
	}
}

void shellsort(int nIn[],int nNum,vector<int>& vecG)
{
	for(int i=1;i<=nNum;)
	{
		vecG.push_back(i);
		i=i*3+1;
	}
	cout<<vecG.size()<<endl;
	for(int i=vecG.size()-1;i>=0;i--)
	{
		cout<<vecG[i];
		if (i!=0)
		{
			cout<<" ";
		}
	}
	cout<<endl;
	for(int i=vecG.size()-1;i>=0;--i)
	{
		insertionSort(nIn,nNum,vecG[i]);
	}
	cout<<nCnt<<endl;
}

int main()
{
	int nNum=0;
	cin>>nNum;
	int nIn[1000000]={0};
	for(int i=0;i<nNum;++i)
	{
		cin>>nIn[i];
	}
	vector<int> vecG;
	shellsort(nIn,nNum,vecG);
	for(int i=0;i< nNum;++i)
	{
		cout<<nIn[i]<<endl;
	}
	return 0;
}

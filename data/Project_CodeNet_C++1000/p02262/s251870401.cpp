#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> G;
long long cnt; 
void insertionSort(vector<int> &A,int n, int g)
{
	for(int i=g;i<n;++i)//i指向待插数的位置
	{
		int v=A[i];
		int j=i-g; //j指向A[i]要插入的位置 
		
		while(j>=0&&A[j]>v)//满足插入条件 ,如果不满足则A[i]的位置不变，i指向下一个待插数 
		{
			A[j+g]=A[j]; //此出不能用A[i]=A[j],j可能会继续往前指，j的后一位并不总是i 
			j-=g;        //A[i]并不急于放入A[j],继续再和前一个位置比较j=j-g
			cnt++; 
		 } 
		 A[j+g]=v;
	} 
	
	
}

void shellsort(vector<int> &A,int n)
{
	//初始化间隔序列 
	for(int h=1;h<=n;)
	{
		G.push_back(h); 
		h=3*h+1;
	}
	//倒叙 循环 进行插入排序
	for(int i=G.size()-1;i>=0;--i)
	{
		insertionSort(A,n,G[i]);
		
	 } 
	
}

int main()
{
	int n,a;
	vector<int> array;
	cin>>n;
	
	for(int i=0;i<n;++i)
	{
	cin>>a;
	array.push_back(a);	
	}
	//排序 
	shellsort(array,n); 
	
	//output 
	cout<<G.size()<<endl;
	for(int p=G.size()-1;p>=0;--p)
	{
		if(p==0)
		cout<<G[p]<<endl;
		else
		cout<<G[p]<<" ";
	}
		
	cout<<cnt<<endl;
	for(int i=0;i<n;++i)
	{
		cout<<array[i]<<endl;
	}
	return 0;
 } 

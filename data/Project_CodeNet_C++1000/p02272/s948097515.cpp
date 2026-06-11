#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;
const int N = 500010;
int n,cnt;
int A[N]; int L[N>>1]; int R[N>>1];
void Merge(int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;

	for(int i = 0; i < n1; i ++)
		L[i] = A[left + i];
	for(int i = 0; i < n2; i ++)
		R[i] = A[mid + i];
	L[n1] = INF; R[n2] = INF;
	int i = 0; int j = 0;
	for(int k = left; k < right; k ++)
	{
		cnt ++;
		if(L[i] <= R[j]) {A[k] = L[i]; i++;}
		else { A[k] = R[j];j++;}
	}
}
void Merge_Sort(int left,int right)
{
  	if (left+1 < right)
  	{
    	int mid = (left + right) >> 1;
        Merge_Sort(left, mid);
        Merge_Sort(mid, right);
        Merge(left, mid, right);
    }
}
void print()
{
	for(int i = 0; i < n; i ++)
	{
		if(i == n-1) printf("%d\n",A[i]);
		else printf("%d ",A[i]);
	}
	printf("%d\n",cnt);
	return ;
}
int main()
{
	cnt = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
		scanf("%d",&A[i]);
	Merge_Sort(0,n);
	print();
	return 0;
}
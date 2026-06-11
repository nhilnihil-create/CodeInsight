
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G;
int cnt = 0;
int pow(int j, int k) {
	if (k == 0)
		return 1;
	else return j*pow(j, k - 1);
}
void insertionSort(int*p,int n,int g) {
	for (int i = g; i < n; i++) {
		int v = p[i];
		int j = i - g;
		while (j >= 0 && p[j] > v) {
			p[j + g] = p[j];
			j -= g;
			cnt=cnt+1;
		}
		p[j + g] = v;
	}
}

void shellSort(int*p, int n) {
	int h = 0;
	for (int i=0;;i++) {
		if (i % 2 == 0)
			h = 9 * pow(4, i / 2) - 9 * pow(2, i / 2) + 1;
		else if (i % 2 == 1)
			h = pow(2, i / 2 + 2)*(pow(2, i / 2 + 2) - 3) + 1;
		if (h > n) break;
		G.push_back(h);
		
	}
	
    for (int i= G.size()-1;i>=0;i--)
	{
		insertionSort(p, n, G[i]);
	}
}

int main()
{
	int n;
	int*seq;
	scanf("%d", &n);
	seq = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);


	shellSort(seq, n);
	printf("%d \n", G.size());
	for (int i = G.size()-1; i >= 0; i--) {
		printf("%d ", G[i]);
		if (i) printf(" ");
	}
	printf("\n%d\n", cnt);
	for (int i = 0; i < n; i++)
		printf("%d\n", seq[i]);



    return 0;
}
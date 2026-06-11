
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> G;
int cnt = 0;
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
	for (int h = 1;;) {
		if (h > n) break;
		G.push_back(h);
		h = 3 * h + 1;
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
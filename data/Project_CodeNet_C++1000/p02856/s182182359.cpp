#include<bits/stdc++.h>
#define WR "txt"

void Open() { freopen(WR".in", "r", stdin); freopen(WR".out", "w", stdout); }
void Close() { fclose(stdin); fclose(stdout); }
using namespace std;
long long Read()  {
	long long val = 0, opt = 1; char ch;
	while (!isdigit(ch = getchar() )) if (ch == '-') opt = -1;
	while (isdigit( ch )) (val *= 10) += ch - '0', ch= getchar();
	return val * opt;
}

long long Sum, n, b, c, Ans;

void work()  {
	n = Read();
	for (int i = 1;i <= n; i++)  {
		b = Read(), c = Read();
		Ans += (c - 1) + (b * c - 1) / 9;
		Sum += (b * c - 1) % 9 + 1; 
	}
	Ans += (n - 1) + (Sum - 1) / 9;
	printf("%lld\n", Ans);
}

int main(void)  {
	//Open();
	work();
	//Close();
	return 0;
}
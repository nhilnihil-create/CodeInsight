#include "bits/stdc++.h"
using namespace std;

void course0();

int main()
{
	int c = 0;
	if (c == 0) course0();
	getchar();
	getchar();
    return 0;
}

void course0()
{
	int N, M, X;
	int cost = 100000000;
	cin >> N >> M >> X;
	bool master = true;
	int price[15];
	int A[15][15];
	for (int i = 0; i < N; i++) {
		cin >> price[i];
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int x = 0; x < (1 << N); x++) {
		int y = x;
		int sum[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int newcost = 0;
        int c = 0;
		while (y > 0) {			
			if (y % 2 == 1) {
				for (int i = 0; i < M; i++) {
					sum[M-1-i] = sum[M-1-i] + A[c][M-1-i];
					
				}
                newcost += price[c];
               
			}
			 y = y >> 1;
			 c++;
		}
        //for (int i = 0; i < N; i++) cout << sum[i] << " ";
        //cout << x << " " << newcost << endl;
        master = true;
		for (int i = 0; i < M; i++) {
			if (sum[i] < X) {
                //cout << "not master" << endl;
				master = false;
                break;
			}
            
		}
        
		if (master == true && cost > newcost) cost = newcost;

	}
	if (master == true) cout << cost << endl;
	else cout << -1 << endl;
}
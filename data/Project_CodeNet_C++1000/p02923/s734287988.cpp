#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H[100000];
	int N, i, j;

	cin >> N;

	for(i = 0; i < N; i++)
        cin >> H[i];

    int maximum_move = 0, moves = 0;
    for(i = 0; i < N - 1; i++)
    {
        if(H[i] >= H[i+1])
            moves++;
        else
            moves = 0;

        if(moves > maximum_move)
            maximum_move = moves;
    }

    cout << maximum_move << endl;

	return 0;
}

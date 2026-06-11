#include <bits/stdc++.h>
using namespace std;

int arr[3][3];

void markBingo(int num)
{
	for(int r = 0 ; r < 3 ; r++){
		for(int c = 0; c < 3; c++){
			if(arr[r][c] == num)
				arr[r][c] = -1;
		}
	}
}

bool checkHorizontal()
{
	bool ok = false;
	for(int r = 0; r < 3 ; r++){
		ok |= ((arr[r][0] == -1) && (arr[r][1] == -1) && (arr[r][2] == -1));
	}
	return ok;
}

bool checkVertical()
{
	bool ok = false;
	for(int c = 0; c < 3 ; c++){
		ok |= ((arr[1][c] == -1) && (arr[0][c] == -1) && (arr[2][c] == -1));
	}
	return ok;
}

bool checkDiagonal()
{
	bool ok = false;
	if(arr[1][1] == -1 && arr[0][0] == -1 && arr[2][2] == -1)
		ok = true;
	if(arr[1][1] == -1 && arr[2][0] == -1 && arr[0][2] == -1)
		ok = true;
	return ok;
}

bool solved()
{
	bool ok = false;
	ok |= checkHorizontal();
	ok |= checkVertical();
	ok |= checkDiagonal();
	return ok;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);


	for(int r = 0 ; r < 3 ; r++){
		for(int c = 0 ; c < 3 ; c++){
			cin >> arr[r][c];
		}
	}

	int N;
	cin >> N;
	
	while(N--)
	{
		int num;
		cin >> num;
		markBingo(num);
	}

	if(solved())
		cout << "Yes" << '\n';
	else cout << "No" << '\n'; 

	return 0;
}
#include <iostream> 

using namespace std;

int main() {

	short N;
	cin >> N;
	short* music_time = new short[N];
	int sleep_time = 0;
	string* title = new string[N],X;

	for(int i = 0; i < N; i++)	cin >> title[i] >> music_time[i];
	cin >> X;
	for (int i = N - 1; title[i] != X; i--)sleep_time += music_time[i];
	cout << sleep_time << endl;
	return 0;
}
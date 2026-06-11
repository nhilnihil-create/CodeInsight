#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	cin >> N;
	char* S = (char*)calloc(N+1, sizeof(char));
	for(int i = 0; i < N; i++){
		cin >> S[i];
	}
	
	int count = 0;
	for(int i = 0; i < N-2; i++){
		if(S[i] == 'A'){
			if(S[i+1] == 'B'){
				if(S[i+2] == 'C'){
					count++;
				}
			}
		}
	}
	cout << count << endl;
	
}

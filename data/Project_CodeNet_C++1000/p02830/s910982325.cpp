#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	char* s = (char*)calloc(n+1, sizeof(char));
	char* t = (char*)calloc(n+1, sizeof(char));
	char* s_t = (char*)calloc(n+n+1, sizeof(char));
	
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	int s_index = 0;
	int t_index = 0;
	for(int i = 0; i < n*2; i++){
		if(i % 2 == 0) s_t[i] = s[s_index++];
		else s_t[i] = t[t_index++];
	}
	
	cout << s_t << endl;
	
}
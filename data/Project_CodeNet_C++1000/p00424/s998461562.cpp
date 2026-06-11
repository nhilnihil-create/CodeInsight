#include<iostream>

using namespace std;

int main()
{
	for(;;){
		char henkan[100000][2];
		char str[100000];
		int n,m;
		char temp;
		bool flg = 0;
		
		cin >> n;
		if(n == 0){
			break;
		}
		
		for(int i = 0; i < n; i++){
			cin >> henkan[i][0] >> henkan[i][1];
		}
		/*
		for(int i = 0; i < n; i++){
			cout << henkan[i][1] << endl;
		}
		*/
		
		cin >> m;
		
		for(int i = 0; i < m; i++){
			cin >> str[i];
		}
		
		for(int i = 0; i < m; i++){
			flg = 0;
			for(int j = 0; j < n; j++){
				if(str[i] == henkan[j][0]){
					temp = henkan[j][1];
					flg = 1;
				}
			}
			if(flg == 1){
				printf("%c",temp);
			}
			else{
				printf("%c",str[i]);
			}
		}
		cout << endl;
	}
}
		
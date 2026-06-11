#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
int n, l = 9;
int s[l];
for(int i = 0;i < 9;i++){
  cin >> s[i];//ビンゴの紙に書いてある数
	}
cin >> n;
int a[n];
for(int i = 0;i < n;i++){
  cin >> a[i];//ビンゴをぐるぐる回して出で来た数
	}
int b[n];
for(int i = 0;i < 9;i++){
	int k = 0;
	for(int j = 0;j < n;j++){
		if(s[i] == a[j]){//入力した数字何れかとs[i]が同じであればk++;即ち１
			k++;
			}
		}
	b[i] = k;//s[i] == a[どれか]であれば1,otherwise,0
	}
if(b[0] == 1 && b[1] == 1 && b[2] == 1){
	cout << "Yes" << '\n';
	}
else if(b[3] == 1 && b[4] == 1 && b[5] == 1){
	cout << "Yes" << '\n';
	}
else if(b[6] == 1 && b[7] == 1 && b[8] == 1){
	cout << "Yes" << '\n';
	}
else if(b[0] == 1 && b[3] == 1 && b[6] == 1){
	cout << "Yes" << '\n';
	}
else if(b[1] == 1 && b[4] == 1 && b[7] == 1){
	cout << "Yes" << '\n';
	}
else if(b[2] == 1 && b[5] == 1 && b[8] == 1){
	cout << "Yes" << '\n';
	}
else if(b[0] == 1 && b[4] == 1 && b[8] == 1){
	cout << "Yes" << '\n';
	}
else if(b[6] == 1 && b[4] == 1 && b[2] == 1){
	cout << "Yes" << '\n';
	}
else{
	cout << "No" << '\n';
	}
/*for(int i = 0;i < 9;i++){
	cout << b[i] << '\n';
	}*/
return 0;
}
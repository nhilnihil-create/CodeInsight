#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int arr[6] = {100,101,102,103,104,105};
int i;
vector<bool> pos;

bool check(int x){
	if(x < 0){
		return false;
	}
	if(x == 0){
		return true;
	}
	if(x < i){
		return pos[x];
	}
	for(int i{0};i < 6;i++){
		if(check(x-arr[i])){
			pos[x-arr[i]] = true;
			return true;
		}
	}
	pos[x] = false;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	cin >> x;
	pos.resize(x+1,false);
	pos[0] = true;
	for(i = 1;i <= x;i++){
		pos[i] = check(i);
	}
	cout << pos[x];
	return 0;
}




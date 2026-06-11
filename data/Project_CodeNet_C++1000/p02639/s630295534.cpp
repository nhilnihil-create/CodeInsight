#include <bits/stdc++.h>
using namespace std;
 
int main(){
int A=0, T=0, R=0, N = 0, K = 1;
char H = 'a';
vector<int> M(5);

for(int i = 0;i< 5;i++){
	cin >> M.at(i);
	if(M.at(i) == 0) T = i+1;
}

cout << T << endl;

}
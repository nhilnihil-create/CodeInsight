#include<iostream>
#include<queue>
using  namespace std;
int main(void){
	int n, q, s;
	cin >> n >> q;
	string m;
	queue<string> name;
	queue<int> time;  
	for(int i = 0; i < n; i++){
		cin >> m >> s;
		name.push(m);
		time.push(s);
	}
	int t = 0; 
	while(!name.empty()){
		string a = name.front();
		int b = time.front();
		if(b <= q){
			t += b;
			cout << a << ' ' << t << endl;
			name.pop();
			time.pop();
		}
		else{
			t += q;
			name.pop();
			time.pop();
			name.push(a);
			time.push(b-q);
		}
	}
	return 0;

}

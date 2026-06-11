#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
	int input;
	priority_queue<int> pq;
	string operation;
	while(true){
		cin >> operation;
		if (operation == "end"){ break; }
		else if (operation == "extract"){ cout << pq.top() << endl; pq.pop();  }
		else if (operation == "insert"){
			int input;
			cin >> input;
			pq.push(input);
		}
	}

	
	return 0;


}
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	list<int> links;
	string command;
	int key;
	for(int i=0; i<n; i++){
		cin >> command;
		if(command[0] == 'i'){
			cin >> key;
			links.push_front(key);
		}else if(command[0] == 'd'){
			if(command.length()>6){
				if(command[6] == 'F'){
					links.pop_front();
				}else if(command[6] == 'L'){
					links.pop_back();
				}
			}else{
				cin >> key;
				for(list<int>::iterator it = links.begin(); it != links.end(); it++){
					if(*it == key){
						links.erase(it);
						break;
					}
				}
			}
		}
	}
	int i=0;
	for(list<int>::iterator it = links.begin(); it != links.end(); it++){
		if(i++) cout << " ";
		cout << *it;
	}
	cout << endl;
	return 0;
}
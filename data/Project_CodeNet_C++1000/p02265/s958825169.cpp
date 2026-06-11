#include <bits/stdc++.h>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	list<int> lis;
	int cnt;
	cin >> cnt;
	string tmp;
	int tmpI;
	for(int i=0; i<cnt; i++){
		cin >> tmp;
		if(tmp[0] == 'i'){	//insert x
			cin >> tmpI;
			lis.push_front(tmpI);
		}else if(tmp == "delete"){	//delete x
			cin >> tmpI;
			for(list<int>::iterator it = lis.begin(); it != lis.end(); it++){
				if(*it == tmpI){
					lis.erase(it);
					break;
				}
			}
		}else if(tmp[6] == 'F'){	//deleteF
			lis.pop_front();
		}else{	//deleteL
			lis.pop_back();
		}
	}
	for(list<int>::iterator it = lis.begin(); it != lis.end(); it++){
		if(it != lis.begin()){
			cout << " ";
		}
		cout << *it;
	}
	cout << endl;
	return 0;
}
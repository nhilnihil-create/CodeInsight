#include <iostream>
using namespace std;

int main() {
	int h, w;
	bool flag;
	while(h+w){
		flag = true;
		cin >> h >> w;
		for(int i=0; i < h; i++){
			for(int j =0; j < w; j++){
				if(flag)cout << "#";
				else cout << ".";
				flag = !flag;
			}
			cout << endl;
			if(w%2-1)flag = !flag;
		}
		if(h+w)cout<<endl;
	}
	// your code goes here
	return 0;
}
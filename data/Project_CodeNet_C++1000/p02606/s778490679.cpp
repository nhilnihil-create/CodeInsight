#include <iostream>

using namespace std;

int main(){
	int x,y,z;
    cin >> x >> y >> z;
    int cntr = 0;
    for(int i = x; i <= y; i++){
    	if(i % z == 0) cntr++;
    }
    cout << cntr;
}

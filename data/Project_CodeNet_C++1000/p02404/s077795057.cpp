#include <iostream>

using namespace std;
 
int main() {
    while(true) {
    	int h, w;
    	cin >> h >> w;
    	if(h==0 && w==0) {
    		break;
    	}
    	for(int i=0; i<h; i++) {
    		if(i==0 || i==h-1) {
    			for(int j=0; j<w; j++) {
	    			cout << "#";
	    		}
    		}else {
    			cout << "#";
    			for(int k=0; k<w-2; k++) {
    				cout << ".";
    			}
    			cout << "#";
    		}
    		cout << endl;
    	}
    	cout << endl;
    }
}

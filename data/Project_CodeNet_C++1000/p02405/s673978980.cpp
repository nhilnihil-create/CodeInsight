#include <iostream>

using namespace std;

int main() {
    while(true) {
    	int h, w;
    	cin >> h >> w;
    	if(h==0 && w==0) {
    		break;
    	}
    	for(int i=1; i<=h; i++) {
    		if(i%2==0) {
    			for(int j=1; j<=w; j++) {
    				if(j%2==0) {
    					cout << "#";	
    				}else {
    					cout << ".";
    				}
    			}
    		}else {
    			for(int k=1; k<=w; k++) {
    				if(k%2==0) {
    					cout << ".";
    				}else {
    					cout << "#";	
    				}
    			}
    		}
    		cout << endl;
    	}
    	cout << endl;
    }
}

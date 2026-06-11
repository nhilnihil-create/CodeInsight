#include <iostream>
using namespace std;
int main(){
    int r,c,A;
    cin >> r >> c;
    int hyo[100][100]={};
    int newer[r+c]={};
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		cin >> A;
    		hyo[i][j]=A;
    	}
    }
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++){
    		newer[i]+=hyo[i][j];
    	}
    }
    for(int i=0;i<c;i++){
    	for(int j=0;j<r;j++){
    		newer[r+i]+=hyo[j][i];
    	}
    }
    for(int i=0;i<r;i++){
    	for(int j=0;j<c+1;j++){
    		if(j<c){
    			cout << hyo[i][j] << " " ;
    		}
    		else if(j==c){
    			cout << newer[i] << endl;
    		}
    	}
    }
    int x=0;
    for(int i=0;i<c+1;i++){
    	if(i<c){
              cout << newer[i+r] << " ";
    	}
    	else if(i==c){
              cout << x;
    	}
    	x+=newer[i+r];
    }
    cout << endl;
    return 0;
}

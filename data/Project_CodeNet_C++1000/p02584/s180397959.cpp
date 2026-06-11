#include <bits/stdc++.h>
using namespace std;
int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main() {
    long long X,K,D;
    long long count;
    cin >> X >> K >> D;
    
    if(X<0)
        X*=-1;
    count = X/D;
    if(count>K){
        X-=D*K;
        K=0;
    }
    else{
        X-=D*count;
        K-=count;
    }
    if(K%2==0){
        if(X<0)
            X*=-1;
        cout<<X<<endl;
    }
    else
    {
        X-=D;
        if(X<0)
             X*=-1;
        cout<<X<<endl;
    }
    

    
}
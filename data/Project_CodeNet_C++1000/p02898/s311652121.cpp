#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int a, b, c=0;
    cin >> a >> b;
    int arr[a];
    for(int i=0; i<a; i++){
        cin >> arr[i];
        if(arr[i]>=b){
            ++c;
        }
    }
    
    cout << c << endl;
    
    
    
    
    
	return 0;
}
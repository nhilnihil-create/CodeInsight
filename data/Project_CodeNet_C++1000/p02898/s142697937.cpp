#include<iostream>
using namespace std;
int main(){
    int n,k;
    int count = 0;
    cin >> n >> k;
    int h[n];
    for(int i=0; i<n ; i++){
        cin >> h[i];
    }

    for(int i=0; i<n ; i++){
        if(k <= h[i])count++;
    }

    cout << count << endl;

    return 0;
}
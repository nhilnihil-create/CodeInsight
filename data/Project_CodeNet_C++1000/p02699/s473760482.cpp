#include<iostream>
#include<vector>
using namespace std;

int main(){
    int S;
    int W;
    cin >> S >> W;

    if (W >= S){
        cout << "unsafe" << endl;
    }else{
        cout << "safe" << endl;
    }
}
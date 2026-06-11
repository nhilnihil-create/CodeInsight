#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int wrong = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if(x != i+1){
            wrong++;
        }
        if(wrong > 2){
            break;
        }
    }
    if(wrong > 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

}
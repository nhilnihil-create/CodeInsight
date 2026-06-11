#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int s=0;
    s = N/2;
    
    if(N%2==0){
        cout << s << endl;
    }
    else{
        cout << s+1 << endl;
    }

}
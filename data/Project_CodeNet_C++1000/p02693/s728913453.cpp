#include<iostream>
using namespace std;

int main(){
    int K,A,B;
    cin >> K >> A >> B;
    if(B-A>=K-1){
        cout << "OK" << endl;
    }else{
        for(int i=A;i<=B;i++){
            if(i%K==0){
                cout << "OK" << endl;
                return 0;
            }
        }
        cout << "NG" << endl;
    }
}
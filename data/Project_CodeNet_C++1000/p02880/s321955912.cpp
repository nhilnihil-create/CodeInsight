#include<iostream>
using namespace std;

int main(){
    int a;
    bool ada = false;
    cin >> a;
    for(int i=1;i<=9;i++){
        for(int k=1;k<=9;k++){
            if(i*k == a){
                ada = true;
            }
        }
    }
if(ada == true){
    cout << "Yes" << endl;
}else if (ada == false){
    cout << "No" << endl;
  }
}
#include <iostream>

using namespace std;

int main(){
    int x,y,k;
    int total=0;
    cin >> x >> y >> k;
    for(int i=x;i<=y;i++){
        if(i%k==0){
            total+=1;
        }
    }cout << total << endl;
}
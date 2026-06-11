#include <iostream>
using namespace std;

int main(){
int n = 5;
int x;
for(int i = 0;i < n;i++){
    cin >> x;
    if (x == 0){
        cout << i+1 << endl;
        return 0;
    }
}
return 0;
}
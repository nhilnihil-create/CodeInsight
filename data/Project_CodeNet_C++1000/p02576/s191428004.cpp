#include <iostream>
using namespace std;
int main(){
    int n , x , t;
    cin >> n >> x >> t;
    int count =0;
    while (n>0){
        n-=x;
        count++;
    }
    cout << t*count;

}

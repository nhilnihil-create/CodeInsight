#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a%2 == 0) {
            if(!(a%3 == 0 || a%5 == 0)) {
                puts("DENIED");
                return 0;
            }
        }
    }
    puts("APPROVED");
    return 0;
}
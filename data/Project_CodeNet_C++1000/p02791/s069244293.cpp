#include <iostream>

using namespace std;
int main(){
    int n;cin >> n;
    int count=1,min;cin >> min;
    for(int i=1; i<n; i++) {
        int num;cin >> num;
        if(min > num) {
            min = num;
            count++;
        }
        if(min == 1) break;
    }
    cout << count << endl;
}
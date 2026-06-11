#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int start, end, num;
    int count = 0;
    cin >> start >> end >> num;
    for(int i=start; i<=end; i++){
        if(i%num == 0){
            count++;
        }
    }
    cout << count << endl;
}

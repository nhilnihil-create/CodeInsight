#include <iostream>
using namespace std;

#define LISTSIZE 10000
 
int main(){
    int n[LISTSIZE];

    int x = 1;
    int i = 0;
    while (1){
        cin >> x;
        if (x==0) {
            break;
        }

        n[i] = x;
        i += 1;
    }

    for (int t=0; t<i; t=t+1) {
        cout << "Case " << t+1 << ": " << n[t] << endl;
    }

    return 0;
}
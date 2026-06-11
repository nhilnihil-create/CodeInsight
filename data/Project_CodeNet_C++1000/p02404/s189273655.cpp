#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a = 1, b = 1, i = 1;
    while ((a != 0)||(b != 0)){
    	if (i != 1)
            cout << endl;
        i++;
        cin >> a >> b;
        if ((a != 0)||(b != 0))
            for (int i = 1; i <= a; i++){
                for (int j = 1; j <= b; j++)
                    if ((i == 1) || (i == a) || (j == 1) || (j == b))
                    	cout << '#';
                    	else cout << '.';
                cout << endl;
            }
    }
}

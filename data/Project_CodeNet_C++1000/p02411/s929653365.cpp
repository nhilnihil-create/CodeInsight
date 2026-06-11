#include <iostream>
using namespace std; 
int main()
{
    int m = 0;
    int f = 0;
    int r = 0;
    for(int i = 0; i < 100; i++){
        cin >> m >> f >> r;
        if(m == -1 && f == -1 && r == -1) break;
        int s = m + f;
        if(m == -1 || f == -1){
            cout << "F" << endl;
        }else if(s >= 80){
            cout << "A" << endl;
        } else if(s >= 65){
            cout << "B" << endl;
        } else if(s >= 50){
            cout << "C" << endl;
        } else if(s >= 30){
            if(r >= 50){
                cout << "C" << endl;
            } else {
                cout << "D" << endl;
            }
        } else {
            cout << "F" << endl;
        }
    }
    
	return 0;

}


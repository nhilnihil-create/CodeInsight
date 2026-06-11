#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    while(1){
        int a,b,i,j;
        cin >> a >> b;
        if(a==0 && b==0){
            break;
        }
        else{
            for(j=0; j<a; j++){
                for(i=0; i<b; i++){
                    if(i==(b-1)){
                        cout << "#" << endl;
                    }
                    else{
                        cout << "#";
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}


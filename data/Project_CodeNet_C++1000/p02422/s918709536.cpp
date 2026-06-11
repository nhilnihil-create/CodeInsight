#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str, inst, p;
    int a, b, q;
    cin >> str >> q;
    
    for(int i=0; i<q; i++){
        cin >> inst;
        if(inst == "replace"){
            cin >> a >> b >> p;
            str = str.substr(0, a) + p + str.substr(b+1);
        }else if(inst == "reverse"){
            cin >> a >> b;
            string sub = "";
            for(int j=b; a<=j; j--){
                sub += str.at(j);
            }
            str = str.substr(0, a) + sub + str.substr(b+1);
        }else if(inst == "print"){
            cin >> a >> b;
            cout << str.substr(a, (b-a+1)) << endl;
        }
    }
    return 0;
}
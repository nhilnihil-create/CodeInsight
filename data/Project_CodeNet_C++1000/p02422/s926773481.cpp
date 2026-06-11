#include <iostream>

using namespace std;

int main(){

        string str,order,addedStr,tmp;
        int roop, a, b;
        cin >> str;
        cin >> roop;

        for(int i = 0; i < roop; i++){
                cin >> order;
                cin >> a >> b;
                if(order == "print"){
                        cout << str.substr(a,b-(a - 1)) << endl;
                }

                else if(order == "reverse"){
                                for(int j = b; j >= a; j--){
                                tmp += str.at(j);
                                }
                                str.replace(a,b-(a - 1),tmp);
                                tmp = "";
                }

                else{
                        cin >> addedStr;
                        str.replace(a,b-(a - 1),addedStr);
                }
        }

        return 0;
}
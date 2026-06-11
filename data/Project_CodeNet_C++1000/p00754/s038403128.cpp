#include <iostream>
#include <stack>
using namespace std;

char bl[5]= "([)]";

int main(){
    char str[101];
    while(1){
        cin.getline(str, 101);
        if(str[0]=='.') break;

        stack<char> seq;
        for(int i=0; str[i]!='.'; i++){
            for(int j=0; j<2; j++){
                if(str[i]==bl[j]){
                    seq.push(str[i]);
                }
            }
            for(int j=2; j<4; j++){
                if(str[i]==bl[j]){
                    if(seq.empty() || seq.top()!=bl[j-2]){
                        seq.push(0);
                        break;
                    }else{
                        seq.pop();
                    }
                }
            }
        }
        if(seq.empty()){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

    return 0;
}
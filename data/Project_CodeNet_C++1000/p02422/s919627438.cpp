#include <iostream>
#include <string>
using namespace std;


int main() {
    string s, ope, p, tmp;
    int i, j, h, num, start, end;

    cin >> s;
    cin >> num;

    for(j=0;j<num;j++){

        cin >> ope;
       
        if(ope == "replace"){
                cin >> start >> end >> p;
                for(i=start;i<=end;i++){
                    s[i] = p[i-start];
                }            
        }else if(ope == "reverse"){
                cin >> start >> end;
                for(i=start;i<=end;i++){
                    tmp[i-start] = s[i];
                }  
                for(i=start;i<=end;i++){
                    s[end-i+start] = tmp[i-start];
                }
        }else{
            cin >> start >> end;
            for(i=start;i<=end;i++){
               cout << s[i];
            }
            cout << endl;
        }

    }

    return 0;
}


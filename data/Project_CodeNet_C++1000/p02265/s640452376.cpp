#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    list<int> List;   //?????????
    int CommandNum;     //????????°
    string Command;
    int Number;
    
    List.clear();
    
    cin >> CommandNum;
    
    for(int i = 0; i < CommandNum; i++){
        cin >> Command;
        if(Command == "insert"){    //??????????????\
            cin >> Number;
            List.push_front(Number);
        } else if(Command == "delete"){ //????????????????????????
            cin >> Number;
            list<int>::iterator it = find(List.begin(), List.end(), Number);
            if(it != List.end())    List.erase(it);
        } else if(Command == "deleteFirst"){    //????????????
            List.pop_front();
        } else{ //????°???????
            List.pop_back();
        }
    }
    
    for(list<int>::iterator it = List.begin(); it != List.end(); it++){
        if(it != List.begin())   cout << " ";
        cout << *it;
    }
    cout << endl;
}
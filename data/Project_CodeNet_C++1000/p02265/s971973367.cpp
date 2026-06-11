#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    int q,x;
    string command;

    list<int> v;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> command;
        if(command == "insert"){
            cin >> x;
            v.push_front(x);
        }else if(command == "deleteFirst"){
            v.pop_front();
        }else if(command == "deleteLast"){
            v.pop_back();
        }else if(command == "delete"){
            cin >> x;
            for (list<int>::iterator it = v.begin(); it != v.end() ; it++) {
                if(*it == x){
                    v.erase(it);
                    break;
                }
            }
        }
    }
    int i = 0;
    for(auto itr = v.begin(); itr != v.end(); ++itr) {
        if ( i ++) cout << " ";
        cout << *itr;
    }
    cout << endl;
    return 0;
}
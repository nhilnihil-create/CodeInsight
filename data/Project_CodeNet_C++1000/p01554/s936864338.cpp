#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
    vector<string> a;
    string b;
    int n,m;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> b;
        a.push_back(b);
    }
    cin >> m;
    int flag;
    int tobira = 0;
    for(int i = 0;i < m;i++){
        flag = 0;
        cin >> b;
        for(int j = 0;j < a.size();j++){
            if(b == a[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            if(tobira == 0){
                cout << "Opened by " << b <<endl;
                tobira = 1;
            }
            else if(tobira == 1){
                cout << "Closed by " << b <<endl;
                tobira = 0;
            }
        }
        else if(flag == 0){
            cout << "Unknown " << b << endl;
        }
    }
    return 0;
}
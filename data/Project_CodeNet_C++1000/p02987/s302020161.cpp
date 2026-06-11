#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    set<int> set{s.at(0),s.at(1),s.at(2),s.at(3)};
    if(set.size()==2){
        int count = 0;
        for(int i=1;i<4;i++){
            if(s.at(0)==s.at(i))count++;
        }
        if(count==1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl; 
        }
    }else{
        cout << "No" << endl;
    }
}

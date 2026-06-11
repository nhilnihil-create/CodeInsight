#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i;
    int h=0;
    for(i=0;i<s.size();i++){
        if(i%2==0){
            if(s.at(i)!='h'){
                h++;
            }
        }
        else{
            if(s.at(i)!='i'){
                h++;
            }
        }
    }
    if((h==0)&&(s.size()%2==0)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}
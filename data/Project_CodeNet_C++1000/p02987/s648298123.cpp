#include <iostream>
#include <string>
using namespace std;

const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
    string s;
    int k=0;
    int count[27]={0};
    cin >> s;
    for (int i=0;i<4;i++){
        for (int j=0;j<26;j++){
            if(s[i]==alpha[j]){
                count[j]++;
            }
        }
    }
    for(int i=0;i<27;i++){
        if(count[i]==2){
            k++;
        }else if(count[i]!=0){
            cout <<"No";
            return 0;
        }
    }
    if(k==2){
        cout << "Yes";
    }else{
        cout <<"No";
    }
    return 0;
}
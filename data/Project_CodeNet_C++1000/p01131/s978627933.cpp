#include<iostream>
#include<vector>
using namespace std;

vector<char> Button[9];

void hoge(){

    Button[0].push_back('.');
    Button[0].push_back(',');
    Button[0].push_back('!');
    Button[0].push_back('?');
    Button[0].push_back(' ');
    string s="abcdefghijklmnopqrstuvwxyz";
    int k=0;
    for(int i=1; i<=8; i++){
        for(int j=0; j<(i==6||i==8? 4: 3); j++){
            Button[i].push_back(s[k]);
            k++;
        }
    }
}

int main(){

    hoge();

    int n;
    cin>> n;
    for(int i=0; i<n; i++){
        string s;
        cin>> s;
        char p='0';
        int k=0;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='0'){
                if(p!='0'){
                    int mo=(p=='1'? 5: (p=='7'||p=='9'? 4: 3));
                    cout<< Button[p-'0'-1][(k-1+mo)%mo];
                }
                k=0;
            }else{
                k++;
            }
            p=s[j];
        }
        cout<< endl;
    }

    return 0;
}
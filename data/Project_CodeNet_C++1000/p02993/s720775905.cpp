#include<iostream>
#include<string>
using namespace std;
int main (void){

    string s;
    int a = 0;


      cin >> s;

    for(int i = 1;i < 4;i++ ){
        
        
        if(s[i] == s[i - 1])
        {
        a = 1;
        break;
        }
        
        
    } 

    if(a == 1)
    cout << "Bad" << endl;
    else if(a == 0) 
    cout << "Good" << endl; 



    return 0;
}
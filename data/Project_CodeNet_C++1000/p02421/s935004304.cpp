#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    int i,n,j;
    int taro_p = 0, hanako_p = 0;
    string taro, hanako;
    
    cin >> n;
    
    for(i = 0; i < n; i++ ){
            cin >>  taro >>  hanako;
            
            if((taro > hanako) == 1){
                taro_p = taro_p + 3;
                }
            
            if((taro < hanako) == 1){
                hanako_p = hanako_p + 3;
                }
            
            if((taro == hanako) == 1){
                hanako_p++; taro_p++;
                }
        }
        
    cout << taro_p << " " << hanako_p << endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    int tpoint = 0;
    int hpoint = 0;
    string taro, hanako;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> taro >> hanako;
        
        if(taro > hanako){
            tpoint = tpoint + 3;
        }
        else if(taro < hanako){
            hpoint = hpoint + 3;
        }
        else{
            tpoint = tpoint + 1;
            hpoint = hpoint + 1;
        }
    }
    
    cout << tpoint << " " << hpoint << endl;
}

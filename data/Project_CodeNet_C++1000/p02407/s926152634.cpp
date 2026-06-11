#include<iostream>
using namespace std;
int main(){
    int n,i;
    int num[1000];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num[i];
    }
    for(i=n-1;i>-1;i--){
        if(i==0){
            cout << num[i] << endl;
            return 0;
        }else{
            cout << num[i] << " ";
        }
    }
    return 0;    
}
#include <iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int d1[n],d2[n],cnt=0;
    for(int i=0;i<n;i++){
        cin >> d1[i] >> d2[i];
        if(cnt==3){
            break;
        }else if(d1[i]==d2[i]){
            cnt++;
        }else{
            cnt = 0;
        }
    }
    if(cnt==3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
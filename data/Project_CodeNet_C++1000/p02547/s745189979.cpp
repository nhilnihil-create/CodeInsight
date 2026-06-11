#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,Dd[100][2] ;
        cin >> N;
    for(int i = 1 ; i <= N ;i++){
        cin >> Dd[i][0] >> Dd[i][1];
    }
    for(int j = 1 ; j <= N-2 ; j++){
        if(Dd[j][0] == Dd[j][1] && Dd[j+1][0] == Dd[j+1][1] && Dd[j+2][0] == Dd[j+2][1]){
            cout << "Yes" << endl;
            return 0;
        }
        
    }
    cout << "No" << endl;
    return 0;
}
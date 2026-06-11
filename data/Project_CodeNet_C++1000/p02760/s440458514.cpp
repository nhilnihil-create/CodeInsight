#include<bits/stdc++.h>
using namespace std;
int main(){
    int flag = 0;
    int matrix[3][3], n;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> matrix[i][j];

    cin >> n;
    vector<int> B(n);
    for(int i = 0; i < n; i++)
        cin >> B[i];
    int c = 0;
    while(c < n){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(matrix[i][j] ==  B[c]){
                    matrix[i][j] = 0;
                    break;
                }
            }
        }
        c++;
    }
    
    if(matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2]) flag = 1;
    else if(matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2]) flag = 1;
    else if(matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2]) flag = 1;
    
    else if(matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0]) flag = 1;
    else if(matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]) flag = 1;
    else if(matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2]) flag = 1;

    else if(matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) flag = 1;
    else if(matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]) flag = 1;

    if(flag == 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;    
    return 0;
}

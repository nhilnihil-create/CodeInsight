#include<iostream>
using namespace std;

int saiki(int n, int s, int i, int *result){
    if(n <= 0){
        if(s == 0){
            *result += 1;
        }
    }else{
        for(int j=i;j<10;j++){
            saiki(n-1,s-j,j+1,result);
        }
    }
}
int main(){
    int n, s;
    int result;
    cin >> n >> s;
    while(n || s){
        result = 0;
        saiki(n, s, 0, &result);
        cout << result << endl;
        cin >> n >> s;
    }
    return 0;
}
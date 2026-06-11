#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int answer = 0;
    int min = 2000000;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(min >= num){
        min = num;
        answer++;
        }
    }
    cout << answer << endl;
}